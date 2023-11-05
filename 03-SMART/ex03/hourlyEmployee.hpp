/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hourlyEmployee.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:09:27 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/04 16:58:50 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOURLYEMPLOYEE_HPP
# define HOURLYEMPLOYEE_HPP

#include "employee.hpp"

class TempWorker: public Employee
{
	public:
		TempWorker(int hourlyValue): Employee(hourlyValue) {}
		~TempWorker() {}
		int executeWorkday()
		{
			return (this->hourlyValue * 7);
		}
};

#endif