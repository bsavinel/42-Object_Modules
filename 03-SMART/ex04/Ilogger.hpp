/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ilogger.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:20:01 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/05 16:49:24 by bsavinel         ###   ########.fr       */
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
		StreamLogger(std::ostream &stream): stream(stream) {}
		StreamLogger(std::ostream &stream, Header *header): stream(stream), header(header) {}
		~StreamLogger() {}

		virtual void write(std::string str)
		{
			if (header)
				std::cout << header->getHeader();
			std::cout << str << std::endl;	
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

class FileLoger: public Ilogger
{
	public:
		FileLoger(int fd): fd(fd) {}
		FileLoger(int fd, Header *header): fd(fd), header(header) {}
		~FileLoger() {}

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