/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hourlyEmployee.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:09:27 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/12 17:29:03 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOURLYEMPLOYEE_HPP
# define HOURLYEMPLOYEE_HPP

#include "employee.hpp"

class TempWorker: public Employee
{
	public:
		TempWorker(std::string name, int hourlyValue): Employee(name, hourlyValue), time_work(0) {}
		~TempWorker() {}
		
		int executeWorkday()
		{
			time_work += 7;
			return (this->hourlyValue * 7);
		}

		const int &getTimeWork()
		{
			return (this->time_work);
		}

	protected:
		int time_work;
};

#endif