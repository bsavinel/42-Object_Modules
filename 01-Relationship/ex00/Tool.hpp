/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tool.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:25:00 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/07 13:07:24 by bsavinel         ###   ########.fr       */
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
		virtual void use() = 0;
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
	virtual void use();
};

struct Hammer: public Tool
{
	Hammer();
	~Hammer();
	virtual void use();	
};

#endif