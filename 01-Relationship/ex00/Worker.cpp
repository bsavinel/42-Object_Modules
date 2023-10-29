/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:59:28 by bsavinel          #+#    #+#             */
/*   Updated: 2023/10/29 16:30:35 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Worker.hpp"

Worker::Worker(Position pos, Statistic stat): coordonnee(pos), stat(stat) {}
Worker::Worker() {}
Worker::~Worker() {}

const Position &Worker::getCoordonnee()
{
	return this->coordonnee;
}

const Statistic &Worker::getStat()
{
	return this->stat;
}

void Worker::giveTool(Tool *toolGiven)
{
	this->tool = toolGiven;
}

Tool *Worker::takenAwayTool()
{
	Tool *tmp = this->tool;
	return tmp;
}

void Worker::addWorkshop(Workshop *newshop)
{
	if(this->workshops.insert(newshop).second)
		newshop->addWorker(this);
}
		
void Worker::deleteWorkshop(Workshop *deletedshop)
{
	if(this->workshops.erase(deletedshop))
		deletedshop->deleteWorker(this);
}

void Worker::work()
{
	if (workshops.empty())
	{
		std::cout << "I work anywhere" << std::endl;
		return ;
	}
	std::cout << "I work in this adress :";
	for (std::set<Workshop *>::iterator it = this->workshops.begin(); it != this->workshops.end(); it++)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}
