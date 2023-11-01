/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:08:05 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/01 14:35:03 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_HPP
# define SHAPE_HPP

class Shape
{
	public:
		Shape() {}
		virtual ~Shape() {}
		
		virtual float getArea() = 0;
		virtual float getPerimeter() = 0;
};

#endif