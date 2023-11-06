/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:00:22 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/06 12:04:07 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKER_HPP
# define WORKER_HPP

class Worker;

# include <set>
# include <iostream>
#include "Tool.hpp"
#include "Workshop.hpp"

struct Position
{
	Position(int X, int Y, int Z);
	~Position();
	int x;
	int y;
	int z;
};

struct Statistic
{
	Statistic(int Level, int Exp);
	~Statistic();
	int level;
	int exp;
};

class Worker {
	public:
		Worker(Position pos, Statistic stat);
		~Worker();
		
		const Position &getCoordonnee();
		const Statistic &getStat();

		void giveTool(Tool *toolGiven);
		Tool *takenAwayTool();

		void addWorkshop(Workshop *newshop);
		void deleteWorkshop(Workshop *deletedshop);
		void work();
		
	private:
		
		std::set<Workshop *> workshops;
		Position coordonnee;
		Statistic stat;
		Tool *tool;
};

#endif