/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:11:19 by bsavinel          #+#    #+#             */
/*   Updated: 2023/10/29 16:24:35 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <cstddef>
// #include <set>
// #include <iostream>

// struct Position
// {
// 	int x;
// 	int y;
// 	int z;
// };

// struct Statistic
// {
// 	int level;
// 	int exp;
// };

// struct Tool
// {
// 	virtual ~Tool() = 0;
// 	int numberOfUses;
// };

// struct Shovel: public Tool
// {
// };

// struct Hammer: public Tool
// {
// };

// class Workshop;

// class Worker {
// 	public:
// 		Worker(Position pos, Statistic stat): coordonnee(pos), stat(stat) {}
// 		~Worker() {}
		
// 		void giveTool(Tool *toolGiven)
// 		{
// 			this->tool = toolGiven;
// 		}

// 		Tool *takenAwayTool()
// 		{
// 			Tool *tmp = this->tool;
// 		}

// 		void addWorker(Workshop *newshop)
// 		{
// 			this->workshops.insert(newshop);
// 		}
		
// 		void deleteWorker(Workshop *deletedshop)
// 		{
// 			this->workshops.erase(deletedshop);
// 		}

// 		void work()
// 		{
// 			if (workshops.empty())
// 			{
// 				std::cout << "I work anywhere" << std::endl;
// 				return ;
// 			}
// 			std::cout << "I work in this adress :";
// 			for (std::set<Workshop *>::iterator it = this->workshops.begin(); it != this->workshops.end(); it++)
// 			{
// 				std::cout << " " << *it;
// 			}
// 			std::cout << std::endl;
// 		}
		
// 	private:
// 		Worker() {}
		
// 		std::set<Workshop *> workshops;
// 		Position coordonnee;
// 		Statistic stat;
// 		Tool *tool;
// };

// class Workshop
// {
// 	public:
// 		void addWorker(Worker *newWorker)
// 		{
// 			this->workers.insert(newWorker);
// 		}
		
// 		void deleteWorker(Worker *deletedWorker)
// 		{
// 			this->workers.erase(deletedWorker);
// 		}
		
// 		void executeWorkDay()
// 		{
// 			for (std::set<Worker *>::iterator it = this->workers.begin(); it != this->workers.end(); it++)
// 			{
// 				(*it)->work();
// 			}
// 		}
		
// 	private:
// 		std::set<Worker *> workers;
// };

#include "Tool.hpp"
#include "Worker.hpp"
#include "Workshop.hpp"

int main()
{
	return 0;
}