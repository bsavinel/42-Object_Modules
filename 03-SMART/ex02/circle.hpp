/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:07:41 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/01 14:37:27 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCLE_HPP
# define CIRCLE_HPP

# include "shape.hpp"

class Circle : public Shape
{
	public:
		Circle(float radius): radius(radius) {}
		~Circle() {}

		float getArea()
		{
			return (3.14 * radius * radius);
		}
		float getPerimeter()
		{
			return (2 * 3.14 * radius);
		}

	private:
		float radius;

};

#endif