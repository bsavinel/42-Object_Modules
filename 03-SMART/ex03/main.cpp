/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:09:29 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/12 17:38:02 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "employeeManagement.hpp"
#include "salariedEmployee.hpp"
#include "hourlyEmployee.hpp"

int main()
{
	EmployeeManager manager;

	Apprentice* emp1 = new Apprentice("John", 100);
	Apprentice* emp2 = new Apprentice("Jack", 100);
	TempWorker* emp3 = new TempWorker("Bob", 100);
	ContractEmployee* emp4= new ContractEmployee("Bryan", 100);
	ContractEmployee* emp5 = new ContractEmployee("Bryan", 100);
	
	manager.addEmployee(emp1);
	manager.addEmployee(emp2);
	manager.addEmployee(emp3);
	manager.addEmployee(emp4);
	manager.addEmployee(emp5);
	
	emp1->setSchoolPeriode(true);
	emp4->setVacation(4);

	manager.executeWorkday();
	manager.calculatePayroll();

	std::cout << "Info of " << emp1->getName() << ": Time in school -> " << emp1->getTimeInSchool() << " Time not work -> " << emp1->getTimeNotWork() << std::endl;
	std::cout << "Info of " << emp2->getName() << ": Time in school -> " << emp2->getTimeInSchool() << " Time not work -> " << emp2->getTimeNotWork() << std::endl;
	std::cout << "Info of " << emp3->getName() << ": Time work -> " << emp3->getTimeWork() << std::endl;
	std::cout << "Info of " << emp4->getName() << ": Time not work -> " << emp4->getTimeNotWork() << std::endl;
	std::cout << "Info of " << emp5->getName() << ": Time not work -> " << emp5->getTimeNotWork() << std::endl;
	

	delete emp1;
	delete emp2;
	delete emp3;
	delete emp4;
	delete emp5;

	return (0);
}