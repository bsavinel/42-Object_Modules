/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ilogger.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:20:01 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/05 17:17:53 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ILOGGER_HPP
# define ILOGGER_HPP

#include <iostream>
#include <stdio.h>
#include <string>
#include "Header.hpp"

class Ilogger
{
	public:
		Ilogger() {}
		virtual ~Ilogger() {}
		virtual void write(std::string) = 0;
};

class StreamLogger: public Ilogger
{
	public:
		StreamLogger(std::ostream &stream): stream(stream), header(NULL) {}
		StreamLogger(std::ostream &stream, Header *header): stream(stream), header(header) {}
		~StreamLogger() {}

		virtual void write(std::string str)
		{
			if (header)
				stream << header->getHeader();
			stream << str << std::endl;	
		}
	
		void setHeader(Header *header)
		{
			this->header = header;
		}

		void removeHeader()
		{
			this->header = NULL;
		}
	private:
		std::ostream &stream;
		Header *header;
};

class FileLogger: public Ilogger
{
	public:
		FileLogger(int fd): fd(fd), header(NULL) {}
		FileLogger(int fd, Header *header): fd(fd), header(header) {}
		~FileLogger() {}

		virtual void write(std::string str)
		{
			if (header)
				dprintf(fd, "%s", header->getHeader().c_str());
			dprintf(fd, "%s\n", str.c_str());
		}

		void setFd(int fd)
		{
			this->fd = fd;
		}

		void setHeader(Header *header)
		{
			this->header = header;
		}

		void removeHeader()
		{
			this->header = NULL;
		}
	private:
		int fd;
		Header *header;
};

#endif