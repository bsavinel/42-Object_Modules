/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   salariedEmployee.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:09:31 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/04 17:12:38 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SALARIEDEMPLOYEE_HPP
# define SALARIEDEMPLOYEE_HPP

#include "employee.hpp"

class ContractEmployee : public Employee
{
	public:
		ContractEmployee(int hourlyValue): Employee(hourlyValue) {}
		~ContractEmployee() {}

		void setVacation(int time)
		{
			this->timeVacation = time;
		}
		
		const int &getVacation()
		{
			return (this->timeVacation);
		}

		int executeWorkday()
		{
			if (this->timeVacation >= 7)
			{
				this->timeVacation -= 7;
				return 0;
			}
			int value = this->hourlyValue * (7 - this->timeVacation);
			this->timeVacation = 0;		
			return value;
		}

	protected:
		int timeVacation;
};

class Apprentice: public ContractEmployee
{
	public:
		Apprentice(int hourlyValue): ContractEmployee(hourlyValue) {}
		~Apprentice() {}

		void setSchoolPeriode(bool periode)
		{
			this->SchoolPeriode = periode;
		}
		
		const bool &isInSchool()
		{
			return this->SchoolPeriode;
		}

		int executeWorkday()
		{
			int value = this->ContractEmployee::executeWorkday();
			if (this->SchoolPeriode)
				value *= 0.5;
			return value;
		}

		protected:
			bool SchoolPeriode;
};

#endif