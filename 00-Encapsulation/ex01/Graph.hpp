/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:29:45 by bsavinel          #+#    #+#             */
/*   Updated: 2023/10/29 13:31:09 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_HPP
# define GRAPH_HPP

#include <vector>
#include "Vector2.hpp"
#include <string>

class Graph
{
	public:
		Graph(unsigned int lenght, unsigned int height);
		~Graph();

		void addPoint(Vector2 &point);
		void addPoint(float x, float y);

		const Vector2 &getSize() const;
		void printGraph();

	private:
		Graph();

		Vector2 size;
		std::vector<Vector2> points;
};

#endif