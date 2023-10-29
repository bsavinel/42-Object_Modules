/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:00:22 by bsavinel          #+#    #+#             */
/*   Updated: 2023/10/29 16:29:30 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKER_HPP
# define WORKER_HPP

# include <set>
# include <iostream>
# include "Tool.hpp"

class Worker;
#include "Workshop.hpp"

struct Position
{
	int x;
	int y;
	int z;
};

struct Statistic
{
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
		Worker();
		
		std::set<Workshop *> workshops;
		Position coordonnee;
		Statistic stat;
		Tool *tool;
};

#endif