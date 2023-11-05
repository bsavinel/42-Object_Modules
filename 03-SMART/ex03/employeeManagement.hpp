/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   employeeManagement.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:09:25 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/04 16:43:31 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EMPLOYEEMANAGEMENT_HPP
# define EMPLOYEEMANAGEMENT_HPP

#include "employee.hpp"
#include <set>

class EmployeeManager
{
	public:
		EmployeeManager() {}
		~EmployeeManager() {}
		void addEmployee(Employee* emp)
		{
			employees.insert(emp);
		}
		
		void removeEmployee(Employee* emp)
		{
			employees.erase(emp);
		}

		void executeWorkday()
		{}

		void calculatePayroll()
		{}

	private:
		std::set<Employee*> employees;

};

#endif