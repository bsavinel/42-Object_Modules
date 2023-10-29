/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:31:29 by bsavinel          #+#    #+#             */
/*   Updated: 2023/10/29 13:41:54 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graph.hpp"
#include <iostream>

Graph::Graph(unsigned int lenght, unsigned int height): size(Vector2(lenght, height))
{}

Graph::~Graph()
{}

void Graph::addPoint(Vector2 &point)
{
	points.push_back(point);
}

void Graph::addPoint(float x, float y)
{
	points.push_back(Vector2(x, y));
}

const Vector2 &Graph::getSize() const
{
	return size;
}

void Graph::printGraph()
{
	std::string str(size.X * 2, ' ');
	for (int i = 0; i < size.X * 2; i++)
	{
		if (i % 2 == 0)
			str[i] = '*';
	}
	std::vector<std::string> zone(size.Y, str);

	for (std::vector<Vector2>::iterator it = points.begin(); it != points.end(); it++)
	{
		if (it->X >= 0 && it->X <= size.X && it->Y >= 0 && it->Y <= size.Y)
			zone[it->Y][((int)it->X) * 2] = 'X';
	}
	for (int i = this->size.Y - 1; i >= 0; i--)
	{
		std::cout << i << " " << zone[i] << std::endl;
	}
	std::cout << " " ;
	for (int i = 0; i < size.Y; i++)
	{
		std::cout << " " << i;
	}
	std::cout << std::endl;
}

Graph::Graph(): size(Vector2(0,0))
{}
