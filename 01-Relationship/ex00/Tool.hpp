/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tool.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:25:00 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/06 12:04:30 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOL_HPP
# define TOOL_HPP

struct Tool;

#include <string>
#include "Worker.hpp"

struct Tool
{
	public:
		Tool();
		virtual ~Tool();
		virtual std::string getType() = 0;
	private:
		friend class Worker;
		void setWorker(Worker *worker);
		Worker *getWorker();
		Worker *worker;
};

struct Shovel: public Tool
{
	Shovel();
	~Shovel();
	virtual std::string getType();
};

struct Hammer: public Tool
{
	Hammer();
	~Hammer();
	virtual std::string getType();	
};

#endif