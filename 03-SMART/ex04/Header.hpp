/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:48:17 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/05 17:11:30 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
# define HEADER_HPP

#include <ctime>
#include <iomanip>

class Header
{
	public:
		Header() {}
		virtual ~Header() {}

		virtual std::string getHeader() const = 0;
	private:
		std::string header;
};

class DateHeader: public Header
{
	public:
		DateHeader() {}
		~DateHeader() {}

		std::string getHeader() const
		{
			char buffer[90];

			std::time_t now = std::time(0);

			std::strftime(buffer, 80, "%Y-%m-%d %H:%M:%S : ", std::localtime(&now));
			return std::string(buffer);
		}
};

class StringHeader: public Header
{
	public:
		StringHeader(std::string header): header(header) {}
		~StringHeader() {}

		std::string getHeader() const
		{
			return header;
		}

	private:
		std::string header;
};

#endif