/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Workshop.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:00:25 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/06 12:05:14 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKSHOP_HPP
# define WORKSHOP_HPP

class Workshop;

#include <set>
#include "Worker.hpp"

class Workshop
{
	public:
		Workshop();
		~Workshop();
		void addWorker(Worker *newWorker);
		void deleteWorker(Worker *deletedWorker);

		void executeWorkDay();
		
	private:
		std::set<Worker *> workers;
};

#endif