/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:51:39 by bsavinel          #+#    #+#             */
/*   Updated: 2023/10/29 13:24:30 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DivideAndConquer.hpp"
#include "color.hpp"

int main()
{
	Bank myBank;

	int bobId = myBank.createAccount();
	int robId = myBank.createAccount();

	std::cout << YELLOW << "Bank liquidity : " << NO_COLOR << myBank.getLiquidity() << std::endl;
	std::cout << YELLOW << "Bob account id : " << NO_COLOR << bobId << std::endl;
	std::cout << YELLOW << "Rob account id : " << NO_COLOR << robId << std::endl;

	std::cout << BLUE << "Amount of bob : " << NO_COLOR << myBank[bobId].getValue() << std::endl;

	myBank.makeDeposit(bobId, 2000000);
	std::cout << BLUE << "Amount of bob : " << NO_COLOR << myBank[bobId].getValue() << std::endl;
	std::cout << YELLOW << "Bank liquidity : " << NO_COLOR << myBank.getLiquidity() << std::endl;

	std::cout << PURPLE << "Amount of rob : " << NO_COLOR << myBank[robId].getValue() << std::endl;
	try
	{
		myBank.makeWithdrawls(robId, 1000);
	}
	catch (const Bank::WhitdrawlsImpossible &e)
	{
		std::cout << RED << e.what() << NO_COLOR << std::endl;
	}
	try
	{
		myBank.makeLoan(robId, 99999999);
	}
	catch (const Bank::LoanImpossible &e)
	{
		std::cout << RED << e.what() << NO_COLOR << std::endl;
	}

	myBank.makeLoan(robId, 1000);
	std::cout << PURPLE  << "Amount of rob : " << NO_COLOR << myBank[robId].getValue() << std::endl;
	std::cout << YELLOW << "Bank liquidity : " << NO_COLOR << myBank.getLiquidity() << std::endl;


	myBank.makeWithdrawls(robId, 1000);
	std::cout << PURPLE  << "Amount of rob : " << NO_COLOR << myBank[robId].getValue() << std::endl;

	myBank.deleteAccount(robId);
	try
	{
		int robAmount = myBank[robId].getValue();
		std::cout << PURPLE  << "Amount of rob : " << NO_COLOR << robAmount << std::endl;
	}
	catch (const Bank::IdNotExist &e)
	{
		std::cout << RED << e.what() << NO_COLOR << std::endl;
	}
}
