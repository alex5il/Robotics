#include "Robot.h"
#include "Manager.h"
#include "Plans/PlnObstacleAvoid.h"

#include "Map/Map.h"
#include "PathFinder/AStar.h"
#include "Configurations/ConfigurationManager.h"
#include <iostream>
#include "Waypoints/WaypointsManager.h"

#include <map>

using namespace std;

int main() {
	//Map test

	Map* map = Map::getInstance();
	map->createGrid(false);

	// A start test
	AStar* astr = new AStar();

	std::map<Location, Location> came_from;
	std::map<Location, float> cost_so_far;

	vector<Location> path = astr->runAstar(map->getGraph(),
			map->getStartLocation(), map->getEndLocation(), came_from,
			cost_so_far);

	// print test
	for (int i = 0; i < path.size(); i++) {
		map->getGraph()->edges[path[i].posY][path[i].posX].cellType =
				CURRENT_CELL;
	}

	map->printMap();

	// SHIT CODE!!!!!===============================

/*	map->createGrid(true);

	//vector<Location> inversePath;
	for (int i=0; i<path.size(); i++) {
		path[i].posY = 380 - path[i].posY;
		//inversePath.push_back(path[i].posY);
	}

	// print test
	for (int i = 0; i < path.size(); i++) {
		map->getGraph()->edges[path[i].posY][path[i].posX].cellType =
				CURRENT_CELL;
	}

	map->printMap();*/


	Robot robot("localhost", 6665);
	PlnObstacleAvoid plan(&robot);
	Manager manager(&robot, &plan, path);
	manager.run();

	Map::deleteInstance();

	return 0;
}
