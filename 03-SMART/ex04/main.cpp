/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:47:00 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/05 17:19:05 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ilogger.hpp"
#include "Header.hpp"
#include <vector>

int main()
{
	std::vector<Ilogger*> loggers;
	Header *HDate = new DateHeader();
	Header *HString = new StringHeader("Header of logger : ");
	loggers.push_back(new StreamLogger(std::cout));
	loggers.push_back(new StreamLogger(std::cout, HDate));
	loggers.push_back(new StreamLogger(std::cout, HString));
	loggers.push_back(new FileLogger(1));
	loggers.push_back(new FileLogger(1, HDate));
	loggers.push_back(new FileLogger(1, HString));

	for (std::vector<Ilogger*>::iterator it = loggers.begin(); it != loggers.end(); it++)
	{
		(*it)->write("Hello World");
	}

	for (std::vector<Ilogger*>::iterator it = loggers.begin(); it != loggers.end(); it++)
	{
		delete *it;
	}
	delete HDate;
	delete HString;
}