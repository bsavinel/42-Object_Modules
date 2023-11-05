/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:48:17 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/05 16:53:56 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
# define HEADER_HPP

#include <ctime>
#include <sstream>
#include <iomanip>

// class Header
// {
// 	public:
// 		Header()
// 		{
// 			time_t t = std::time(nullptr);
// 			tm time = *std::localtime(&t);

// 			std::ostringstream oss;
// 			oss << std::put_time(&time, "%d-%m-%Y %H-%M-%S : ");
// 			header = oss.str();
// 		}
	
// 		Header(std::string header): header(header) {}
// 		~Header() {}

// 		const std::string &getHeader() const
// 		{
// 			return header;
// 		}

// 		void setHeader(const std::string &header)
// 		{
// 			this->header = header;
// 		}

// 		void dateHeader()
// 		{
// 			time_t t = std::time(nullptr);
// 			tm time = *std::localtime(&t);

// 			std::ostringstream oss;
// 			oss << std::put_time(&time, "%d-%m-%Y %H-%M-%S : ");
// 			header = oss.str();
// 		}

// 	private:
// 		std::string header;
// };

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
			time_t t = std::time(nullptr);
			tm time = *std::localtime(&t);

			std::ostringstream oss;
			oss << std::put_time(&time, "%d-%m-%Y %H-%M-%S : ");
			return oss.str();
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