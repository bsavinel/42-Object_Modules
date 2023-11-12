/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packageReductionDiscount.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:13:11 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/12 15:49:43 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PACKAGEREDUCTIONDISCOUNT_HPP
# define PACKAGEREDUCTIONDISCOUNT_HPP

#include "command.hpp"

class PackageReductionDiscount: public Command
{
	public:
		PackageReductionDiscount(const Command &cmd): Command(cmd) {}
		~PackageReductionDiscount() {}

		float applyDiscount(float price)
		{
			if (price > 150)
				return price - 10;
			return price;
		}
};

#endif