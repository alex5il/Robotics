#ifndef WAYPOINTSMANAGER_H_
#define WAYPOINTSMANAGER_H_

#include "Waypoint.h"
#include <vector>

using namespace std;

class WaypointsManager {

private:
	vector<Waypoint> waypoints;
	unsigned short currWaypoint;
	static WaypointsManager* Instance;

	WaypointsManager();
	~WaypointsManager();
public:
	static WaypointsManager* getInstance();
	void createWaypoints(vector<Location> path);
	Waypoint* getFirst();
	Waypoint* getNext();
	Waypoint* getCurr();
	bool isWaypointFront(float x, float y, float yaw);
	bool isWaypointLeft(float x, float y, float yaw);
	bool isWaypointRight(float x, float y, float yaw);
	void printCurrWaypoint();
	static void deleteInstance();
};

#endif /* WAYPOINTSMANAGER_H_ */
