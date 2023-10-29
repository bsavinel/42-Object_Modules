/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DivideAndConquer.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:51:25 by bsavinel          #+#    #+#             */
/*   Updated: 2023/10/29 13:05:10 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIVIDEANDCONQUER_HPP
# define DIVIDEANDCONQUER_HPP

#include <map>
#include <stdexcept>

class Bank
{
	public:
		class Account
		{
			public:
				const int &getValue() const;
				const int &getId() const;

			private:
				friend class Bank;
				
				Account();
				Account(unsigned int id);
				~Account();
				
				class WhitdrawlsImpossible: public std::exception
				{
					public:
						virtual const char* what() const throw();
				};
				
				void addMoney(int amount);
				bool subMoney(int amount);

				int id;
				int value;
		};

	public:
		Bank();
		~Bank();
		
		class IdNotExist: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class WhitdrawlsImpossible: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class LoanImpossible: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		unsigned int createAccount();
		void deleteAccount(unsigned int id);

		void makeDeposit(int id, unsigned int amount);
		void makeLoan(int id, int amount);
		void makeWithdrawls(unsigned int id, unsigned int amount);

		const Account &operator[](int id) const;
		const int &getLiquidity() const;

	private:
		int liquidity;
		static unsigned int nb_acount;
		std::map<unsigned int, Account *> clientAccounts;
};

#endif