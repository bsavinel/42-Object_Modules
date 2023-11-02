/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:13:06 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/02 16:12:10 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include "command.hpp"
#include "packageReductionDiscount.hpp"
#include "thuesdayDiscount.hpp"

tm *getNextTuesday()
{
    time_t now = time(0);
    tm *currentTime = localtime(&now);

    int daysUntilTuesday = (7 - currentTime->tm_wday + 2) % 7;
    int secondsUntilTuesday = daysUntilTuesday * 24 * 60 * 60;
    time_t nextTuesdayTime = now + secondsUntilTuesday;
    return localtime(&nextTuesdayTime);
}

tm *getNextFriday()
{
    time_t now = time(0);
    tm *currentTime = localtime(&now);

    int daysUntilTuesday = (7 - currentTime->tm_wday + 5) % 7;
    int secondsUntilTuesday = daysUntilTuesday * 24 * 60 * 60;
    time_t nextTuesdayTime = now + secondsUntilTuesday;
    return localtime(&nextTuesdayTime);
}


int main()
{
	Command command1(1, *getNextFriday(), "Bob");
	Command command2(2, *getNextFriday(), "Alice");
	Command command3(3, *getNextFriday(), "Tom");
	Command command4(4, *getNextTuesday(), "Axel");
	
	command1.articles["Banana"] = std::make_pair(1.0, 150);
	command1.articles["Apple"] = std::make_pair(2.0, 5);
	command1.articles["Orange"] = std::make_pair(1.5, 3);

	command2.articles["Banana"] = std::make_pair(1.0, 150);
	command2.articles["Apple"] = std::make_pair(2.0, 5);
	command2.articles["Orange"] = std::make_pair(1.5, 3);

	command3.articles["Banana"] = std::make_pair(1.0, 10);
	command3.articles["Apple"] = std::make_pair(2.0, 5);
	command3.articles["Orange"] = std::make_pair(1.5, 3);

	command4.articles["Banana"] = std::make_pair(1.0, 10);
	command4.articles["Apple"] = std::make_pair(2.0, 5);
	command4.articles["Orange"] = std::make_pair(1.5, 3);

	std::cout << "Command 1: " << command1.get_total_price() << std::endl;
	std::cout << "Command 2: " << PackageReductionDiscount(command2).get_total_price() << std::endl;
	std::cout << "Command 3: " << ThuesdayDiscount(command3).get_total_price() << std::endl;
	std::cout << "Command 4: " << ThuesdayDiscount(command4).get_total_price() << std::endl;
}