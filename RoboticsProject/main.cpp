#include "Robot.h"
#include "Manager.h"
#include "Plans/PlnObstacleAvoid.h"

#include "Map/Map.h"

int main() {
	//Robot robot("localhost",6665);

	Map* map = new Map();

	map->createGridFromImage(map->originalImage);
	map->printMap();

	std::cout << "\n\n\n ============================================== \n\n\n";
	std::cout << "\n\n\n ============================================== \n\n\n";
	std::cout << "\n\n\n ============================================== \n\n\n";
	std::cout << "\n\n\n ============================================== \n\n\n";

	map->inflateImage();
	map->createGridFromImage(map->inflatedImage);
	map->printMap();


	map->createGridWithResolutionFromImage(map->inflatedImage);

//PlnObstacleAvoid plnOA(&robot);
//Manager manager(&robot, &plnOA);

//manager.run();
}
