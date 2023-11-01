/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:11:19 by bsavinel          #+#    #+#             */
/*   Updated: 2023/11/01 12:31:13 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tool.hpp"
#include "Worker.hpp"
#include "Workshop.hpp"

//TODO Mettre des message dans les constructeur car demandere par le sujet et plus facile que de print des adresses pour faire des trucs chelou

int main()
{
	Workshop bricoMarche;
	Workshop LeRoyMerlin;
	Tool *tool;
	Worker tom(Position(10,5,4),Statistic(10,5));
	Worker bob(Position(10,5,4),Statistic(10,5));

	tool = new Shovel();
	tom.giveTool(tool);
	tool = new Hammer();
	bob.giveTool(tool);
	tom.addWorkshop(&bricoMarche);
	tom.addWorkshop(&LeRoyMerlin);
	bob.addWorkshop(&bricoMarche);
	bricoMarche.executeWorkDay();
	tom.deleteWorkshop(&LeRoyMerlin);
	tom.work();
	delete tom.takenAwayTool();
	delete bob.takenAwayTool();
	
	return 0;
}