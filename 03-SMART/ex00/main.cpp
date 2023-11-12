/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:56:07 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/12 15:32:54 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "car.hpp"

#define PRINTSPEED std::cout << "Speed: " << car.get_speed() << std::endl;
#define PRINTANGLE std::cout << "Angle: " << car.get_angle() << std::endl;

int main()
{
	Car car;
	std::cout << "Starting car" << std::endl;
	PRINTSPEED;
	car.start();
	car.accelerate(50);
	PRINTSPEED;
	car.shift_gears_up();
	PRINTSPEED;
	car.accelerate(50);
	PRINTSPEED;
	car.shift_gears_up();
	PRINTSPEED;
	car.accelerate(50);
	PRINTSPEED;
	car.apply_force_on_brakes(20);
	PRINTSPEED;
	car.turn_wheel(90);
	PRINTANGLE;
	car.straighten_wheels();
	PRINTANGLE;
	car.apply_emergency_brakes();
	PRINTSPEED;
	car.stop();
	PRINTSPEED;
}
