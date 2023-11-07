/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:11:19 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/07 13:09:14 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tool.hpp"
#include "Worker.hpp"
#include "Workshop.hpp"

#define NL std::cout << std::endl;

int main()
{
	Workshop bricoMarche;
	NL
	Workshop LeRoyMerlin;
	NL
	Tool *tool;
	NL
	Worker tom(Position(10,5,4),Statistic(10,5));
	NL
	Worker bob(Position(10,5,4),Statistic(10,5));
	NL

	NL
	tool = new Shovel();
	NL
	bob.giveTool(tool);
	NL
	tom.giveTool(tool);
	NL
	tool = new Hammer();
	NL
	bob.giveTool(tool);
	NL
	tom.addWorkshop(&bricoMarche);
	NL
	tom.addWorkshop(&LeRoyMerlin);
	NL
	bob.addWorkshop(&bricoMarche);
	NL
	bricoMarche.executeWorkDay();
	NL
	tom.deleteWorkshop(&LeRoyMerlin);
	NL
	tom.work();
	NL
	delete tom.takenAwayTool();
	NL
	delete bob.takenAwayTool();
	NL
	
	return 0;
}