/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tool.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:24:12 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/01 12:35:13 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tool.hpp"
#include "color.hpp"
#include <iostream>

Tool::Tool()
{
	std::cout << GREEN << "Tool has created type is : ";
}

Tool::~Tool()
{
	std::cout << RED << " tool has destroy" << NO_COLOR << std::endl;
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
	std::cout << PURPLE << "Hammer";
}

std::string Shovel::getType()
{
	return "Shovel";
}

std::string Hammer::getType()
{
	return "Hammer";
}
