/*
 * AStar.h
 *
 *  Created on: Jun 26, 2015
 *      Author: colman
 */

#ifndef ASTAR_H_
#define ASTAR_H_

#include "../Map/Map.h"

#include <vector>
#include <utility>
#include <queue>
#include <map>



using namespace std;


class AStar {


public:

	pair<int, Location> element;

	AStar();
	virtual ~AStar();

	vector<Location> runAstar(Graph* graph,
			   Location start,
			   Location goal,
			   map<Location, Location>& came_from,
			   map<Location, int>& cost_so_far);
};

#endif /* ASTAR_H_ */
