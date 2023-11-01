/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:08:07 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/01 14:45:05 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_HPP
# define TRIANGLE_HPP

#include "shape.hpp"
#include <math.h>

class Triangle: public Shape
{
	public:
		Triangle(float side1,float side2,float side3): side1(side1), side2(side2), side3(side3) {}
		~Triangle() {}

		float getPerimeter()
		{
			return (side1 + side2 + side3);
		}

		float getArea()
		{
			float p = getPerimeter() / 2;
			return (sqrt(p * (p - side1) * (p - side2) * (p - side3)));
		
		}

	private:
		float side1;
		float side2;
		float side3;		
};

#endif