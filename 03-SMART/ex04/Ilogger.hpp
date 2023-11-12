/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ilogger.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:20:01 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/12 17:08:28 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ILOGGER_HPP
# define ILOGGER_HPP

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "Header.hpp"

class Ilogger
{
	public:
		Ilogger() {}
		virtual ~Ilogger() {}
		virtual void write(std::string) = 0;
};

class IModularLoger: public Ilogger
{
	public:
		IModularLoger() {}
		IModularLoger(std::vector<IHeader *> modules): modules(modules) {}
		virtual ~IModularLoger() {}
		

		void write(std::string str)
		{
			std::string output;

			for (std::vector<IHeader *>::iterator it = modules.begin(); it != modules.end(); it++)
			{
				output += (*it)->getHeader();
			}
			output += str;
			_write(output);
		}
	
	protected:
		virtual void _write(std::string &output) = 0;
		std::vector<IHeader *> modules;
			
};

class StreamLogger: public IModularLoger
{
	public:
		StreamLogger(std::ostream &stream): stream(stream) {}
		StreamLogger(std::ostream &stream, std::vector<IHeader *> modules): IModularLoger(modules), stream(stream) {}
		~StreamLogger() {}

	protected:
		void _write(std::string &str)
		{
			stream << str << std::endl;
		}
		
		std::ostream &stream;
};

class FileLogger: public IModularLoger
{
	public:
		FileLogger(int fd): fd(fd) {}
		FileLogger(int fd, std::vector<IHeader *> modules): IModularLoger(modules), fd(fd) {}
		~FileLogger() {}

	protected:
		void _write(std::string &str)
		{
			dprintf(fd, "%s\n", str.c_str());
		}
		
		int fd;
};

#endif