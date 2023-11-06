/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:59:28 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/06 12:16:46 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Worker.hpp"
#include "color.hpp"
#include <iostream>

Position::Position(int X, int Y, int Z)
{
	std::cout << GREEN << "Position has created" << NO_COLOR << std::endl;
	this->x = X;
	this->y = Y;
	this->z = Z;
}

Statistic::Statistic(int Level, int Exp)
{
	std::cout << GREEN << "Statistic has created" << NO_COLOR << std::endl;
	this->level = Level;
	this->exp = Exp;
}

Position::~Position()
{
	std::cout << RED << "Position has destroy" << NO_COLOR << std::endl;
}

Statistic::~Statistic()
{
	std::cout << RED << "Statistic has destroy" << NO_COLOR << std::endl;
}

Worker::Worker(Position pos, Statistic stat): coordonnee(pos), stat(stat), tool(NULL)
{
	std::cout << GREEN << "Worker born" << NO_COLOR << std::endl;
}

Worker::~Worker()
{
	if (this->tool)
		this->tool->setWorker(NULL);
	for (; this->workshops.begin() != this->workshops.end();)
	{
		this->deleteWorkshop(*this->workshops.begin());
	}
	std::cout << RED << "Worker die" << NO_COLOR << std::endl;
}

const Position &Worker::getCoordonnee()
{
	std::cout << GREEN << "getCoordonnee()" << NO_COLOR << std::endl;
	return this->coordonnee;
}

const Statistic &Worker::getStat()
{
	std::cout << GREEN << "getStat()" << NO_COLOR << std::endl;
	return this->stat;
}

void Worker::giveTool(Tool *toolGiven)
{
	Worker *pred = toolGiven->getWorker();
	this->tool = toolGiven;
	if (pred)
		pred->takenAwayTool();
	toolGiven->setWorker(this);
	std::cout << YELLOW << "Worker get a tool" << NO_COLOR << std::endl;
}

Tool *Worker::takenAwayTool()
{
	Tool *tmp = this->tool;
	if (this->tool)
		this->tool->setWorker(NULL);
	this->tool = NULL;
	std::cout << YELLOW << "Worker lose his tool" << NO_COLOR << std::endl;
	return tmp;
}

void Worker::addWorkshop(Workshop *newshop)
{
	std::cout << GREEN << "addWorkshop()" << NO_COLOR << std::endl;
	if(this->workshops.insert(newshop).second)
	{
		std::cout << YELLOW << "Add Workshop in Worker" << NO_COLOR << std::endl;
		newshop->addWorker(this);
	}
}
		
void Worker::deleteWorkshop(Workshop *deletedshop)
{
	std::cout << GREEN << "deleteWorkshop()" << NO_COLOR << std::endl;
	if(this->workshops.erase(deletedshop))
	{
		std::cout << YELLOW << "Remove Workshop in Worker" << NO_COLOR << std::endl;
		deletedshop->deleteWorker(this);
	}
}

void Worker::work()
{
	if (workshops.empty())
	{
		std::cout << "I work anywhere" << std::endl;
		return ;
	}
	if (this->tool)
		std::cout << CYAN << "I work with my " << this->tool->getType() << CYAN << " in this adress :" << NO_COLOR;
	else
		std::cout << CYAN << "I work with no tool in this adress :" << NO_COLOR;
	for (std::set<Workshop *>::iterator it = this->workshops.begin(); it != this->workshops.end(); it++)
	{
		std::cout << BLUE << " " << *it;
	}
	std::cout << NO_COLOR << std::endl;
}
