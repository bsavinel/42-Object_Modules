/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   car.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:56:14 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/12 15:25:22 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAR_HPP
# define CAR_HPP

class Car;
#include "motor.hpp"
#include "wheel.hpp"

class Car
{
	public:
		Car()
		{
			this->motor.gear_box = &gear_box;
			this->gear_box.wheels = &this->direction.wheels;
			this->breaks.wheels = &this->direction.wheels;
		}
		~Car() {}

		void start()
		{
			motor.start();
		}

		void stop()
		{
			gear_box.dead_point();
			motor.stop();
		}
		
		void accelerate(int speed)
		{
			motor.acelerate(speed);
		}

		void shift_gears_up()
		{
			gear_box.shift_up();
		}

		void shift_gears_down()
		{
			gear_box.shift_down();
		}
		
		void reverse()
		{
			gear_box.reverse();
		}

		void turn_wheel(int angle)
		{
			direction.turn(angle);
		}
		
		void straighten_wheels()
		{
			direction.turn(0);
		}
		
		void apply_force_on_brakes(int force)
		{
			breaks.apply(force);
		}
		
		void apply_emergency_brakes()
		{
			breaks.apply_emergency_breaks();
		}

		int get_speed()
		{
			return (this->direction.wheels.speed);
		}

		int get_angle()
		{
			return (this->direction.wheels.angle);
		}
		
	private:
		Breaks breaks;
		Motor motor;
		GearBox gear_box;
		Direction direction;
};

#endif