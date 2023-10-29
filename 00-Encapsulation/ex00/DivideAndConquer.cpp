/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DivideAndConquer.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:51:36 by bsavinel          #+#    #+#             */
/*   Updated: 2023/10/29 13:16:47 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <stdexcept>
#include "DivideAndConquer.hpp"

unsigned int Bank::nb_acount = 0;


/*
 *  Bank::Account methodes
 */

const int &Bank::Account::getValue() const
{
	return this->value;
}

const int &Bank::Account::getId() const
{
	return this->id;
}

Bank::Account::Account(unsigned int id): id(id), value(0)
{}

Bank::Account::Account()
{}

Bank::Account::~Account()
{}

const char* Bank::Account::WhitdrawlsImpossible::what() const throw()
{
	return "Id doesn't exist";
}

void Bank::Account::addMoney(int amount)
{
	value += amount;
}

bool Bank::Account::subMoney(int amount)
{
	if (value < amount)
		throw WhitdrawlsImpossible();
	value -= amount;
	return true;
}

/*
 *  Bank methodes
 */

Bank::Bank(): liquidity(0)
{}

Bank::~Bank()
{}

const char* Bank::IdNotExist::what() const throw()
{
	return "Id doesn't exist";
}

const char* Bank::WhitdrawlsImpossible::what() const throw()
{
	return "Whitdrawls impossible";
}

const char* Bank::LoanImpossible::what() const throw()
{
	return "Loan impossible";
}

unsigned int Bank::createAccount()
{
	Account *newClient = new Account(nb_acount);
	clientAccounts.insert(std::make_pair(nb_acount, newClient));
	return nb_acount++;
}

void Bank::deleteAccount(unsigned int id)
{
	if (!clientAccounts.erase(id))
		throw IdNotExist();
}

void Bank::makeDeposit(int id, unsigned int amount)
{
	try
	{
		Account& client = *clientAccounts.at(id);

		unsigned int taxe = amount * 0.05;
		client.addMoney(amount - taxe);
		this->liquidity += taxe;
	}
	catch (const std::out_of_range &e)
	{
		throw IdNotExist();
	}
}

void Bank::makeLoan(int id, int amount)
{
	try
	{
		Account& client = *clientAccounts.at(id);

		if (amount > liquidity)
			throw LoanImpossible();
		client.addMoney(amount);
		this->liquidity -= amount;
	}
	catch (const std::out_of_range &e)
	{
		throw IdNotExist();
	}
}
		
void Bank::makeWithdrawls(unsigned int id, unsigned int amount)
{
	try
	{
		Account& client = *clientAccounts.at(id);
		client.subMoney(amount);
	}
	catch (const std::out_of_range &e)
	{
		throw IdNotExist();
	}
	catch(const Bank::Account::WhitdrawlsImpossible& e)
	{
		throw WhitdrawlsImpossible();
	}
}

const Bank::Account &Bank::operator[](int id) const
{
	try
	{
		return *clientAccounts.at(id);
	}
	catch (const std::out_of_range &e)
	{
		throw IdNotExist();
	}
}

const int &Bank::getLiquidity() const
{
	return this->liquidity;
}
