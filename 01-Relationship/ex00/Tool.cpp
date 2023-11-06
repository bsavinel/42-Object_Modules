/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tool.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:24:12 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/06 12:17:48 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tool.hpp"
#include "color.hpp"
#include <iostream>

Tool::Tool(): worker(NULL)
{
	std::cout << GREEN << "Tool has created type is : ";
}

Tool::~Tool()
{
	if (this->worker)
		worker->takenAwayTool();
	std::cout << RED << " tool has destroy" << NO_COLOR << std::endl;
}

void Tool::setWorker(Worker *worker)
{
	std::cout << GREEN << "setWorker()" << NO_COLOR << std::endl;
	this->worker = worker;
}

Worker *Tool::getWorker()
{
	std::cout << GREEN << "getWorker()" << NO_COLOR << std::endl;
	return this->worker;
}

Shovel::Shovel()
{
	std::cout << PURPLE << "Shovel" << NO_COLOR << std::endl;
}

Hammer::Hammer()
{
	std::cout << PURPLE << "Hammer" << NO_COLOR << std::endl;
}

Shovel::~Shovel()
{
	std::cout << PURPLE << "Shovel";
}

Hammer::~Hammer()
{
	std::cout << PURPLE << "Hammer" ;
}

std::string Shovel::getType()
{
	std::cout << GREEN << "getType()" << NO_COLOR << std::endl;
	return "Shovel";
}

std::string Hammer::getType()
{
	std::cout << GREEN << "getType()" << NO_COLOR << std::endl;
	return "Hammer";
}
