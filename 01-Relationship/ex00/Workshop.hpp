/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Workshop.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:00:25 by bsavinel          #+#    #+#             */
/*   Updated: 2023/10/29 16:31:16 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKSHOP_HPP
# define WORKSHOP_HPP

#include <set>
class Workshop;
#include "Worker.hpp"

class Workshop
{
	public:
		void addWorker(Worker *newWorker);
		void deleteWorker(Worker *deletedWorker);

		void executeWorkDay();
		
	private:
		std::set<Worker *> workers;
};

#endif