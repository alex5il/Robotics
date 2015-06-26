#include "Robot.h"
#include "Manager.h"
#include "Plans/PlnObstacleAvoid.h"

#include "Map/Map.h"

int main() {
	//Robot robot("localhost",6665);

	Map* map = new Map();

	map->createGrid();

//PlnObstacleAvoid plnOA(&robot);
//Manager manager(&robot, &plnOA);

//manager.run();
}
