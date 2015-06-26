#include "Robot.h"
#include "Manager.h"
#include "Plans/PlnObstacleAvoid.h"

#include "Map/Map.h"
#include "Configurations/ConfigurationManager.h"
#include <iostream>

int main() {

	Map* map = new Map();
	map->createGrid();
//	cout << x;

//Robot robot("localhost",6665);

//	Map* map = new Map();
//
//	map->createGridFromImage(map->originalImage);
//	map->printMap();
//
//	std::cout << "\n\n\n ============================================== \n\n\n";
//	std::cout << "\n\n\n ============================================== \n\n\n";
//	std::cout << "\n\n\n ============================================== \n\n\n";
//	std::cout << "\n\n\n ============================================== \n\n\n";
//
//	map->inflateImage();
//	map->createGridFromImage(map->inflatedImage);
//	map->printMap();
//
//
//	map->createGridWithResolutionFromImage(map->inflatedImage);
<<<<<<< HEAD
=======
	//Robot robot("localhost",6665);
//
//	Map* map = new Map();
//
//	map->createGrid();
>>>>>>> origin/Branch_1

//PlnObstacleAvoid plnOA(&robot);
//Manager manager(&robot, &
}
