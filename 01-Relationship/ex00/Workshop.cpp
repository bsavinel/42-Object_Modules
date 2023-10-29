/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Workshop.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:59:49 by bsavinel          #+#    #+#             */
/*   Updated: 2023/10/29 16:18:58 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Workshop.hpp"

void Workshop::addWorker(Worker *newWorker)
{
	if(this->workers.insert(newWorker).second)
		newWorker->addWorkshop(this);
}
	
void Workshop::deleteWorker(Worker *deletedWorker)
{
	if(this->workers.erase(deletedWorker))
		deletedWorker->deleteWorkshop(this);
}
		
void Workshop::executeWorkDay()
{
	for (std::set<Worker *>::iterator it = this->workers.begin(); it != this->workers.end(); it++)
	{
		(*it)->work();
	}
}
