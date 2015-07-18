#include "WaypointsManager.h"

WaypointsManager* WaypointsManager::Instance = NULL;

WaypointsManager::WaypointsManager() {
	currWaypoint = 0;
}

void WaypointsManager::createWaypoints(vector<Location> path) {
	Location lastDelta;
	Location currDelta;

	lastDelta.posX = path[1].posX - path[0].posX;
	lastDelta.posY = path[1].posY - path[0].posY;

	// Checking for every location of the path if the delta
	// (yaw of the robot advancement) is different from the previous delta.
	for (unsigned int i = 2; i < path.size() - 1; i++) {
		currDelta.posX = path[i].posX - path[i - 1].posX;
		currDelta.posY = path[i].posY - path[i - 1].posY;

		// If the delta has changed - add a previous location as a waypoint.
		if (currDelta.posX != lastDelta.posX
				|| currDelta.posY != lastDelta.posY) {

			waypoints.push_back(
					Waypoint(path[i - 1].posX, path[i - 1].posY,
							stdWaypntRadius));

			lastDelta.posX = currDelta.posX;
			lastDelta.posY = currDelta.posY;
		}
	}

	// Adding the latest location as a waypoint with radius 0.
	waypoints.push_back(
			Waypoint(path[path.size() - 1].posX, path[path.size() - 1].posY,
					fnlWaypntRadius));

	currWaypoint = 0;
}

Waypoint* WaypointsManager::getFirst() {
	currWaypoint = 0;

	if (waypoints.size() == 0)
		return NULL;

	return &waypoints[0];
}

Waypoint* WaypointsManager::getNext() {
	if (currWaypoint < (waypoints.size() - 1)) {

		currWaypoint++;
		return &waypoints[currWaypoint];
	}

	return NULL;
}

Waypoint* WaypointsManager::getCurr() {
	if (waypoints.size() == 0)
		return NULL;

	return &waypoints[currWaypoint];
}

WaypointsManager* WaypointsManager::getInstance() {
	if (!Instance) {
		Instance = new WaypointsManager();
	}

	return Instance;
}

void WaypointsManager::deleteInstance() {
	delete Instance;
}

bool WaypointsManager::isWaypointFront(float x, float y, float yaw) {
	return abs(getCurr()->robotAlignment(x, y, yaw)) <= waypointAlignment;
}

bool WaypointsManager::isWaypointLeft(float x, float y, float yaw) {
	return (getCurr()->robotAlignment(x, y, yaw) < -waypointAlignment);
}

bool WaypointsManager::isWaypointRight(float x, float y, float yaw) {
	return (getCurr()->robotAlignment(x, y, yaw) > waypointAlignment);
}

WaypointsManager::~WaypointsManager() {
}
