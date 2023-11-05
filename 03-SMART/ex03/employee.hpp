/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   employee.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:09:23 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/04 16:53:39 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EMPLOYEE_HPP
# define EMPLOYEE_HPP

class Employee
{
	public:
		Employee(int hourlyValue): hourlyValue(hourlyValue) {}
		virtual ~Employee() {}

		virtual int executeWorkday() = 0;
	protected:
		int hourlyValue;
		
};

#endif