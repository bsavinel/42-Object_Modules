/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:25:50 by bsavinel          #+#    #+#             */
/*   Updated: 2023/10/29 13:43:50 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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