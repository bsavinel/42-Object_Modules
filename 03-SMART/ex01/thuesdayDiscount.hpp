/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thuesdayDiscount.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:13:13 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/02 16:11:16 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THUESDAYDISCOUNT_HPP
# define THUESDAYDISCOUNT_HPP

#include "command.hpp"

class ThuesdayDiscount: private Command
{
	public:
		ThuesdayDiscount(const Command &cmd): Command(cmd) {}
		~ThuesdayDiscount() {}

		float get_total_price()
		{
			float price = Command::get_total_price();
			if (this->getDate().tm_wday == 2)
				return price - (price * 0.10);
			return price;
		}
};

#endif