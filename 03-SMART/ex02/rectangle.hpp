/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:08:02 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/01 14:38:54 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECTANGLE_HPP
# define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle: public Shape
{
	public:
		Rectangle(float width, float height): width(width), height(height) {}
		~Rectangle() {}

		float getArea()
		{
			return (width * height);
		}
		
		float getPerimeter()
		{
			return (2 * (width + height));
		}

	private:
		float width;
		float height;
};

#endif