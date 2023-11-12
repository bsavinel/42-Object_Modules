/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:04:06 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/12 15:25:03 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHEEL_HPP
# define WHEEL_HPP

class Wheels;
class Direction;
class Breaks;
#include "car.hpp"

class Wheels
{
	public:
		Wheels(): angle(0), speed(0) {}
		~Wheels() {}

	private:
		friend class Car;
		friend class GearBox;
		friend class Breaks;
		friend class Direction;
		int angle;
		int speed;
};

class Direction
{
	public:
		Direction() {}
		~Direction() {}
		
		void turn(int angle)
		{
			if (angle >= -90 && angle <= 90)
				this->wheels.angle = angle;
		}

	private:
		friend class Car;
		Wheels wheels;
};

class Breaks
{
	public:
		Breaks() {}
		~Breaks() {}

		void apply(int force)
		{
			if (force > 0)
			{
				if (force < this->wheels->speed)
					this->wheels->speed -= force;
				else
					this->wheels->speed = 0;
			}
		}

		void apply_emergency_breaks()
		{
			this->wheels->speed = 0;
		}
		
	private:
		friend class Car;
		Wheels *wheels;
};


#endif