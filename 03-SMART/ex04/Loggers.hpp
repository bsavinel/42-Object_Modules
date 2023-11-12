/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Loggers.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:57:33 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/12 17:09:34 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGERS_HPP
# define LOGGERS_HPP

#include "Ilogger.hpp"

class DateStreamLogger: public StreamLogger
{
	public:
		DateStreamLogger(std::ostream &stream): StreamLogger(stream)
		{
			modules.push_back(new DateHeader());
		}

		~DateStreamLogger()
		{
			delete modules[0];
		};
};

class StringStreamLogger: public StreamLogger
{
	public:
		StringStreamLogger(std::ostream &stream, std::string header): StreamLogger(stream)
		{
			modules.push_back(new StringHeader(header));
		}

		~StringStreamLogger()
		{
			delete modules[0];
		};
};

class DateStringLogger: public StreamLogger
{
	public:
		DateStringLogger(std::ostream &stream, std::string header): StreamLogger(stream)
		{
			modules.push_back(new DateHeader());
			modules.push_back(new StringHeader(header));
		}

		~DateStringLogger()
		{
			delete modules[0];
			delete modules[1];
		};
};

class DateFileLogger: public FileLogger
{
	public:
		DateFileLogger(int fd): FileLogger(fd)
		{
			modules.push_back(new DateHeader());
		}

		~DateFileLogger()
		{
			delete modules[0];
		};
};

class StringFileLogger: public FileLogger
{
	public:
		StringFileLogger(int fd, std::string header): FileLogger(fd)
		{
			modules.push_back(new StringHeader(header));
		}

		~StringFileLogger()
		{
			delete modules[0];
		};
};

class DateStringFileLogger: public FileLogger
{
	public:
		DateStringFileLogger(int fd, std::string header): FileLogger(fd)
		{
			modules.push_back(new DateHeader());
			modules.push_back(new StringHeader(header));
		}

		~DateStringFileLogger()
		{
			delete modules[0];
			delete modules[1];
		};
};

#endif