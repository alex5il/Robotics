#ifndef WAYPOINTSMANAGER_H_
#define WAYPOINTSMANAGER_H_

#include "../Map/Map.h"
#include "Waypoint.h"
#include <vector>

using namespace std;

class WaypointsManager {

private:
	vector<Waypoint> waypoints;
	short currWaypoint;

public:
	WaypointsManager(vector<Location> path);

	Waypoint* getFirst();
	Waypoint* getNext();

	~WaypointsManager();
};

#endif /* WAYPOINTSMANAGER_H_ */
