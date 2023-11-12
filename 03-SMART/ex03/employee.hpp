/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   employee.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:09:23 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/12 17:28:01 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EMPLOYEE_HPP
# define EMPLOYEE_HPP

#include <string>

class Employee
{
	public:
		Employee(std::string name, int hourlyValue):name(name), hourlyValue(hourlyValue) {}
		virtual ~Employee() {}

		virtual int executeWorkday() = 0;
		
		const std::string &getName()
		{
			return (this->name);
		}
	protected:
		std::string name;
		int hourlyValue;
		
};

#endif