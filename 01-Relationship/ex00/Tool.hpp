/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tool.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:25:00 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/01 11:45:56 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOL_HPP
# define TOOL_HPP

#include <string>

struct Tool
{
	Tool();
	virtual ~Tool();
	virtual std::string getType() = 0;
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