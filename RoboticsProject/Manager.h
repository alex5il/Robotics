#ifndef MANAGER_H_
#define MANAGER_H_
#include "Plans/PlnObstacleAvoid.h"
#include "Robot.h"
#include "SLAM/LocalizationManager.h"
#include "Waypoints/WaypointsManager.h"

class Manager {

private:
	WaypointsManager* _waypMngr;
	LocalizationManager* _locMngr;
	Behavior* _currBeh;
	Robot* _robot;
	Plan* _plan;

public:
	Manager(Robot* robot, Plan* pln, vector<Location> path);
	void run();
	virtual ~Manager();
};

#endif /* MANAGER_H_ */
