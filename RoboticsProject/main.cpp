#include "Robot.h"
#include "Manager.h"
#include "Plans/PlnObstacleAvoid.h"

#include "Map/Map.h"
#include "Configurations/ConfigurationManager.h"
#include <iostream>

int main() {
	int x = ConfigurationManager::getGridResolutionCM();


//	cout << x;

	//Robot robot("localhost",6665);

	Map* map = new Map();

	map->createGrid();

//PlnObstacleAvoid plnOA(&robot);
//Manager manager(&robot, &plnOA);

//manager.run();
}
