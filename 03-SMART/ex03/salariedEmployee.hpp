/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   salariedEmployee.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:09:31 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/12 17:28:54 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SALARIEDEMPLOYEE_HPP
# define SALARIEDEMPLOYEE_HPP

#include "employee.hpp"

class ContractEmployee : public Employee
{
	public:
		ContractEmployee(std::string name, int hourlyValue): Employee(name, hourlyValue), timeNotWork(0) {}
		~ContractEmployee() {}

		void setVacation(int time)
		{
			this->timeVacation = time;
		}
		
		const int &getVacation()
		{
			return (this->timeVacation);
		}

		const int &getTimeNotWork()
		{
			return (this->timeNotWork);
		}

		int executeWorkday()
		{
			int value = 0;
			if (this->timeVacation >= 7)
			{
				this->timeNotWork += 7;
				this->timeVacation -= 7;
			}
			else
			{
				this->timeNotWork += this->timeVacation;
				value = this->hourlyValue * (7 - this->timeVacation);
				this->timeVacation = 0;		
			}
			return value;
		}

	protected:
		int timeVacation;
		int timeNotWork;
};

class Apprentice: public ContractEmployee
{
	public:
		Apprentice(std::string name, int hourlyValue): ContractEmployee(name, hourlyValue), timeInSchool(0) {}
		~Apprentice() {}

		void setSchoolPeriode(bool periode)
		{
			this->SchoolPeriode = periode;
		}
		
		const bool &isInSchool()
		{
			return this->SchoolPeriode;
		}

		const int &getTimeInSchool()
		{
			return this->timeInSchool;
		}

		int executeWorkday()
		{
			int value = this->ContractEmployee::executeWorkday();
			if (this->SchoolPeriode)
			{
				this->timeInSchool += 7;
				value *= 0.5;
			}
			return value;
		}

		protected:
			bool SchoolPeriode;
			int timeInSchool;
};

#endif