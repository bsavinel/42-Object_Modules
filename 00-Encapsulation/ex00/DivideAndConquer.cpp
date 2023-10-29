/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DivideAndConquer.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:51:36 by bsavinel          #+#    #+#             */
/*   Updated: 2023/10/29 12:51:37 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <stdexcept>

class Bank
{
	public:
		class Account
		{
			public:

				const int &getValue() const
				{
					return this->value;
				}

				const int &getId() const
				{
					return this->id;
				}

			private:
				friend class Bank;

				class WhitdrawlsImpossible: public std::exception
				{
					public:
						virtual const char* what() const throw()
						{
							return "Id doesn't exist";
						}
				};

				Account(unsigned int id): id(id), value(0)
				{}

				Account()
				{}

				~Account()
				{}


				void addMoney(int amount)
				{
					value += amount;
				}

				bool subMoney(int amount)
				{
					if (value < amount)
						throw WhitdrawlsImpossible();
					value -= amount;
					return true;
				}

				int id;
				int value;
		};

	public:
		class IdNotExist: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Id doesn't exist";
				}
		};

		class WhitdrawlsImpossible: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Whitdrawls impossible";
				}
		};

		class LoanImpossible: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Loan impossible";
				}
		};

		Bank(): liquidity(0)
		{}

		~Bank()
		{}

		unsigned int createAccount()
		{
			Account *newClient = new Account(nb_acount);
			clientAccounts.insert(std::make_pair(nb_acount, newClient));
			return nb_acount++;
		}

		void deleteAccount(unsigned int id)
		{
			if (!clientAccounts.erase(id))
				throw IdNotExist();
		}

		void makeDeposit(int id, unsigned int amount)
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

		void makeLoan(int id, int amount)
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
		
		void makeWithdrawls(unsigned int id, unsigned int amount)
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

		const Account &operator[](int id) const
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

		const int &getLiquidity() const
		{
			return this->liquidity;
		}

	private:
		int liquidity;
		static unsigned int nb_acount;
		std::map<unsigned int, Account *> clientAccounts;
};