/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packageReductionDiscount.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:13:11 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/01 14:01:43 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PACKAGEREDUCTIONDISCOUNT_HPP
# define PACKAGEREDUCTIONDISCOUNT_HPP

#include "command.hpp"

class PackageReductionDiscount: private Command
{
	public:
		PackageReductionDiscount(const Command &cmd): Command(cmd) {}
		~PackageReductionDiscount() {}

		float get_total_price()
		{
			float price = Command::get_total_price();
			if (price > 150)
				return price - 10;
			return price;
		}
};

#endif