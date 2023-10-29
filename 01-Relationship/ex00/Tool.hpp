/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tool.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:25:00 by bsavinel          #+#    #+#             */
/*   Updated: 2023/10/29 16:25:19 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TOOL_HPP
# define TOOL_HPP

struct Tool
{
	virtual ~Tool() = 0;
	int numberOfUses;
};

struct Shovel: public Tool
{
};

struct Hammer: public Tool
{
};

#endif