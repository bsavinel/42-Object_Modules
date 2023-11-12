/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:47:00 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/12 17:09:04 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Loggers.hpp"
#include <vector>

int main()
{
	std::vector<Ilogger*> loggers;
	loggers.push_back(new StringFileLogger(0, "str: "));
	loggers.push_back(new DateFileLogger(0));
	loggers.push_back(new DateStringFileLogger(0, "str: "));
	loggers.push_back(new StringStreamLogger(std::cout, "str: "));
	loggers.push_back(new DateStreamLogger(std::cout));
	loggers.push_back(new DateStringLogger(std::cout, "str: "));

	for (std::vector<Ilogger*>::iterator it = loggers.begin(); it != loggers.end(); it++)
	{
		(*it)->write("Hello World!");
	}

	for (std::vector<Ilogger*>::iterator it = loggers.begin(); it != loggers.end(); it++)
	{
		delete *it;
	}
}