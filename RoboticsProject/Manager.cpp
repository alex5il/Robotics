#include "Manager.h"
#include <unistd.h>

Manager::Manager(Robot* robot, Plan* pln, vector<Location> path) {
	_robot = robot;
	_plan = pln;
	_currBeh = pln->getStartPoint();
	_waypMngr = WaypointsManager::getInstance();
	_waypMngr->createWaypoints(path);
	_locMngr = LocalizationManager::getInstance();
}
void Manager::run() {
	Particle* estimatedLoc;
	Waypoint* currWay;

	_robot->Read();

	float lastXPos = _robot->getXPosProxy();
	float lastYPos = _robot->getYPosProxy();
	float lastYaw = _robot->getYawProxy();

	currWay = _waypMngr->getFirst();

	if (!(_currBeh->startCond()))
		_currBeh = _currBeh->selectNext();

	while (currWay != NULL) {
		_currBeh->action();

		while (!_currBeh->stopCond() && currWay != NULL) {
//			_currBeh->action(); // remove

//			_robot->setSpeed(0, 0); // remove
			_robot->Read();

			float deltaX = _robot->getXPosProxy() - lastXPos;
			float deltaY = _robot->getYPosProxy() - lastYPos;
			float deltaYaw = _robot->getYawProxy() - lastYaw;

			// Set odometry according to the SLAM filter.
//			_locMngr->update(deltaX, deltaY, deltaYaw, _robot->getLaserScan());
//			estimatedLoc = _locMngr->estimatedLocation();
//			cout << "\n\nEstimated location is: " << "(" << estimatedLoc->x
//					<< ", " << estimatedLoc->y << ", " << estimatedLoc->yaw
//					<< ")\n";
//			_robot->setLocation(estimatedLoc->x, estimatedLoc->y,
//					estimatedLoc->yaw);
			_robot->Read();
//			_robot->setLocation(_robot->getXPosProxy(), _robot->getYPosProxy(),
//					_robot->getYaw());
			cout << "\n\nEstimated location is: " << "("
					<< _robot->getXPosProxy() << ", " << _robot->getYPosProxy()
					<< ", " << _robot->getYawProxy() << ")\n";

			// If waypoint reached - select the next one.
			if (currWay->withinRadius(_robot->getXPosProxy(),
					_robot->getYPosProxy()))
				currWay = _waypMngr->getNext();
		}

		if (currWay != NULL) {
			_robot->setSpeed(0, 0);
			_currBeh = _currBeh->selectNext();
			_robot->Read();
		}
	}
}

Manager::~Manager() {
	WaypointsManager::deleteInstance();
	LocalizationManager::deleteInstance();
}
