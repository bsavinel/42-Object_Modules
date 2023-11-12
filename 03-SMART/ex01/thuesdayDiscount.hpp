/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thuesdayDiscount.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:13:13 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/12 15:49:48 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THUESDAYDISCOUNT_HPP
# define THUESDAYDISCOUNT_HPP

#include "command.hpp"

class ThuesdayDiscount: public Command
{
	public:
		ThuesdayDiscount(const Command &cmd): Command(cmd) {}
		~ThuesdayDiscount() {}

		float applyDiscount(float price)
		{
			if (this->getDate().tm_wday == 2)
				return price - (price * 0.10);
			return price;
		}
};

#endif