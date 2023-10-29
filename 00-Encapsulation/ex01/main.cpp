/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:25:50 by bsavinel          #+#    #+#             */
/*   Updated: 2023/10/29 13:42:20 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <vector>
// #include <string>
// #include <iostream>

// class Vector2
// {
// 	public:
// 		Vector2(float x, float y): X(x), Y(y)
// 		{}

// 		~Vector2()
// 		{}

// 		float X;
// 		float Y;
	
// 	private:
// 		Vector2()
// 		{}
// };

// class Graph
// {
// 	public:
// 		Graph(unsigned int lenght, unsigned int height): size(Vector2(lenght, height))
// 		{}

// 		~Graph()
// 		{}

// 		void addPoint(Vector2 &point)
// 		{
// 			points.push_back(point);
// 		}

// 		void addPoint(float x, float y)
// 		{
// 			points.push_back(Vector2(x, y));
// 		}

// 		const Vector2 &getSize() const
// 		{
// 			return size;
// 		}

// 		void printGraph()
// 		{
// 			std::string str(size.X * 2, ' ');
// 			for (int i = 0; i < size.X * 2; i++)
// 			{
// 				if (i % 2 == 1)
// 					str[i] = '*';
// 			}
// 			std::vector<std::string> zone(size.Y, str);

// 			for (auto it = points.begin(); it != points.end(); it++)
// 			{
// 				if (it->X >= 0 && it->X <= size.X && it->Y >= 0 && it->Y <= size.Y)
// 					zone[it->Y][((int)it->X) * 2] = 'X';
// 			}
// 			for (int i = 0; i < size.Y; i++)
// 			{
// 				std::cout << i << " " << zone[i] << std::endl;
// 			}
// 			std::cout << " " ;
// 			for (int i = 0; i < size.Y; i++)
// 			{
// 				std::cout << " " << i;
// 			}
// 			std::cout << std::endl;
// 		}

// 	private:
// 		Graph(): size(Vector2(0,0))
// 		{}

// 		Vector2 size;
// 		std::vector<Vector2> points;
// };

#include <iostream>
#include "Vector2.hpp"
#include "Graph.hpp"

int main()
{
	Graph g(6,6);
	g.addPoint(0,0);
	g.addPoint(2,2);
	g.addPoint(4,2);
	g.addPoint(2,4);
	g.addPoint(2,0);
	
	g.printGraph();
}