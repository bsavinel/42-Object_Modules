/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:59:28 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/01 12:39:27 by bsavinel         ###   ########.fr       */
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
	for (; this->workshops.begin() != this->workshops.end();)
	{
		this->deleteWorkshop(*this->workshops.begin());
	}
	std::cout << RED << "Worker die" << NO_COLOR << std::endl;
}

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
	std::cout << YELLOW << "Worker get a tool" << NO_COLOR << std::endl;
}

Tool *Worker::takenAwayTool()
{
	Tool *tmp = this->tool;
	this->tool = NULL;
	std::cout << YELLOW << "Worker lose his tool" << NO_COLOR << std::endl;
	return tmp;
}

void Worker::addWorkshop(Workshop *newshop)
{
	if(this->workshops.insert(newshop).second)
	{
		std::cout << YELLOW << "Add Workshop in Worker" << NO_COLOR << std::endl;
		newshop->addWorker(this);
	}
}
		
void Worker::deleteWorkshop(Workshop *deletedshop)
{
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
	std::cout << CYAN << "I work in this adress :" << BLUE;
	for (std::set<Workshop *>::iterator it = this->workshops.begin(); it != this->workshops.end(); it++)
	{
		std::cout << " " << *it;
	}
	std::cout << NO_COLOR << std::endl;
}
