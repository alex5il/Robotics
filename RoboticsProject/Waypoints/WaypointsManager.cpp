#include "WaypointsManager.h"

WaypointsManager::WaypointsManager(vector<Location> path) {
	Location lastDelta;
	Location currDelta;

	// The initial delta is 0.
	lastDelta.posX = path[2].posX - path[1].posX;
	lastDelta.posY = path[2].posY - path[1].posY;

	// Checking for every location of the path if the delta
	// (yaw of the robot advancement) is different from the previous delta.
	for (unsigned int i = 3; i < path.size() - 1; i++) {
		currDelta.posX = path[i].posX - path[i - 1].posX;
		currDelta.posY = path[i].posY - path[i - 1].posY;

		// If the delta has changed - add a previous location as a waypoint.
		if (currDelta.posX != lastDelta.posX
				|| currDelta.posY != lastDelta.posY) {

			waypoints.push_back(Waypoint(path[i - 1].posX, path[i - 1].posY));
		}
	}

	// Adding the latest location as a waypoint.
	waypoints.push_back(
			Waypoint(path[path.size() - 1].posX, path[path.size() - 1].posY));

	this->currWaypoint = 0;
}

WaypointsManager::~WaypointsManager() {
}
