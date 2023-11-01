/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:07:27 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/01 14:51:23 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rectangle.hpp"
#include "triangle.hpp"
#include "circle.hpp"
#include "color.hpp"
#include <iostream>

void printInfoShape(Shape *shape)
{
	std::cout << YELLOW << "\tPerimeter: " << PURPLE << shape->getPerimeter() << NO_COLOR << std::endl;
	std::cout << YELLOW << "\tArea:      " << PURPLE << shape->getArea() << NO_COLOR << std::endl;
}

int main()
{
	Shape *rectangle = new Rectangle(5, 10);
	Shape *triangle = new Triangle(5, 10, 15);
	Shape *circle = new Circle(5);
	
	std::cout << GREEN << "Rectangle: " << NO_COLOR << std::endl;
	printInfoShape(rectangle);
	std::cout << std::endl;
	std::cout << GREEN << "Triangle: " << NO_COLOR << std::endl;
	printInfoShape(triangle);
	std::cout << std::endl;
	std::cout << GREEN << "Circle: " << NO_COLOR << std::endl;
	printInfoShape(circle);
	return (0);
}