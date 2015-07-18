#include "Manager.h"

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
	short scansNum = 0;

	_robot->Read();

	float lastXPos = ConfigurationManager::getStartLocationX();
	float lastYPos = ConfigurationManager::getStartLocationY();
	float lastYaw = ConfigurationManager::getStartLocationYaw();

	currWay = _waypMngr->getFirst();

	if (!(_currBeh->startCond()))
		_currBeh = _currBeh->selectNext();

	while (currWay != NULL) {
		_currBeh->action();

		while (!_currBeh->stopCond() && currWay != NULL) {
			if (scansNum < 30) {
				scansNum++;
				break;
			}

			_robot->setSpeed(0, 0); //TODO: remove
			_robot->Read();

			float deltaX = _robot->getXPos() - lastXPos;
			float deltaY = _robot->getYPos() - lastYPos;
			float deltaYaw = _robot->getYaw() - lastYaw;

			// Set odometry according to the SLAM filter.
			_locMngr->update(deltaX, deltaY, deltaYaw, _robot->getLaserScan());
			estimatedLoc = _locMngr->estimatedLocation();
			_robot->setOdometry(estimatedLoc->x, estimatedLoc->y,
					estimatedLoc->yaw);

			// If waypoint reached - select the next one.
			if (currWay->withinRadius(_robot->getXPos(), _robot->getYPos()))
				currWay = _waypMngr->getNext();

			_currBeh->action(); // TODO: remove
			scansNum = 0;
		}

		if (currWay != NULL) {
			_currBeh = _currBeh->selectNext();
			_robot->Read();
		}
	}
}

Manager::~Manager() {
	WaypointsManager::deleteInstance();
	LocalizationManager::deleteInstance();
}
