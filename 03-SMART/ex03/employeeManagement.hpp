/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   employeeManagement.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:09:25 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/12 17:29:48 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EMPLOYEEMANAGEMENT_HPP
# define EMPLOYEEMANAGEMENT_HPP

#include "employee.hpp"
#include <iostream>
#include <set>
#include <map>

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
		{
			int payroll;
			for (std::set<Employee*>::iterator it = employees.begin(); it != employees.end(); it++)
			{
				payroll = (*it)->executeWorkday();
				payrolls[*it] += payroll;
			}
		}

		void calculatePayroll()
		{
			unsigned int total = 0;
			for (std::map<Employee*, int>::iterator it = payrolls.begin(); it != payrolls.end(); it++)
			{
				std::cout << "Payroll for " << (*it).first->getName() << ": " << (*it).second << std::endl;
			}
			std::cout << "Total payroll: " << total << std::endl;
		}

	private:
		std::set<Employee*> employees;
		std::map<Employee*, int> payrolls;

};

#endif