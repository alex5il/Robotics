/*
 * main.cpp
 *
 *  Created on: May 22, 2015
 *      Author: user
 */

#include "Robot.h"
#include "Manager.h"
#include "Plans/PlnObstacleAvoid.h"

#include "Map/Map.h"
int main()
{
	//Robot robot("localhost",6665);



	Map* map = new Map();

	map->createGridFromImage();
	map->inflateImage();

	map->printMap();

	std::cout << "\n\n\n ============================================== \n\n\n";




	//PlnObstacleAvoid plnOA(&robot);
	//Manager manager(&robot, &plnOA);

	//manager.run();
}
