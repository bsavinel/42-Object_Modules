/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:09:07 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/12 15:33:23 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOTOR_HPP
# define MOTOR_HPP

class GearBox;
class Motor;
#include "wheel.hpp"
#include "car.hpp"

class GearBox
{
	public:
		GearBox(): level(0) {}
		~GearBox() {}

		void shift_up()
		{
			if (level < 6)
				level++;
		}
		
		void shift_down()
		{
			if (level > 0)
				level--;
		}

		void reverse()
		{
			level = -1;
		}

		void dead_point()
		{
			level = 0;
		}
		
		int get_gear_level()
		{
			return (level);
		}

		void transmiteSpeed(int MotorSpeed)
		{
			if (level == 0)
				wheels->speed = 0;
			else
				wheels->speed = MotorSpeed * (level / 10.0);
		}

		int getSpeed()
		{
			return (wheels->speed);
		}

	private:
		friend class Car;
		int level;
		Wheels *wheels;
};

class Motor
{
	public:
		Motor(): MotorSpeed(0), IsStart(false) {}
		~Motor() {}
		
		void start()
		{
			IsStart = true;
		}

		void stop()
		{
			MotorSpeed = 0;
			IsStart = false;
			gear_box->transmiteSpeed(0);
		}

		void acelerate(int speed)
		{
			if (!IsStart)
				return ;
			MotorSpeed += speed;
			gear_box->transmiteSpeed(MotorSpeed);
		}
		
	private:
		friend class Car;
		GearBox *gear_box;
		int MotorSpeed;
		bool IsStart;
};

#endif