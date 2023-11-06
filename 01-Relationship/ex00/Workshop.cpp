/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Workshop.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:59:49 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/06 12:10:48 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Workshop.hpp"
#include "color.hpp"

Workshop::Workshop()
{
	std::cout << GREEN << "Worshop has build" << NO_COLOR << std::endl;
}

Workshop::~Workshop()
{
	for (;this->workers.begin() != this->workers.end();)
	{
		this->deleteWorker(*this->workers.begin());
	}
	std::cout << RED << "Worshop his destroy" << NO_COLOR << std::endl;
}

void Workshop::addWorker(Worker *newWorker)
{
	std::cout << GREEN << "addWorker()" << std::endl;
	if(this->workers.insert(newWorker).second)
	{
		std::cout << YELLOW << "Add Worker in Workshop" << NO_COLOR << std::endl;
		newWorker->addWorkshop(this);
	}
}
	
void Workshop::deleteWorker(Worker *deletedWorker)
{
	std::cout << GREEN << "deleteWorker()" << std::endl;
	if(this->workers.erase(deletedWorker))
	{
		std::cout << YELLOW << "Remove Worker in Workshop" << NO_COLOR << std::endl;
		deletedWorker->deleteWorkshop(this);
	}
}
		
void Workshop::executeWorkDay()
{
	std::cout << GREEN << "executeWorkDay()" << std::endl;
	for (std::set<Worker *>::iterator it = this->workers.begin(); it != this->workers.end(); it++)
	{
		(*it)->work();
	}
}
