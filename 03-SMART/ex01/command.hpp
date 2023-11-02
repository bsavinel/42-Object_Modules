/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:13:08 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/02 16:10:40 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP

#include <ctime>
#include <string>
#include <map>

class Command
{
	public:
		Command(int id, tm date, std::string name): ID(id), date(date), client(name) {}
		
		virtual ~Command() {}
		Command(const Command &cmd)
		{
			this->client = cmd.client;
			this->articles = cmd.articles;
			this->date = cmd.date;
			this->ID = cmd.ID;
		}
		
		virtual float get_total_price()
		{
			float cout = 0;
			for (std::map<std::string, std::pair<float, int> >::iterator it = articles.begin(); it != articles.end(); it++)
			{
				cout += it->second.second * it->second.first;
			}
			return cout;
		}
	
		int getID() { return this->ID; }
		tm getDate() { return this->date; }
		std::string getClient() { return this->client; }

		std::map<std::string, std::pair<float, int> > articles;

	private:
		int ID;
		tm date;
		std::string client;
		
};

#endif