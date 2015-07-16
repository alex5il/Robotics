#include "Manager.h"

Manager::Manager(Robot* robot, Plan* pln, vector<Location> path) {
	_robot = robot;
	_plan = pln;
	_currBeh = pln->getStartPoint();
	_waypMngr = new WaypointsManager(path);
	_locMngr = new LocalizationManager();
}
void Manager::run() {
	_robot->Read();

	float lastXPos = _robot->getXPos();
	float lastYPos = _robot->getYPos();
	float lastYaw = _robot->getYaw();

	if (!(_currBeh->startCond()))
		return;

	while (_currBeh != NULL) {
		while (!_currBeh->stopCond()) {
			_currBeh->action();
			_robot->Read();

			float deltaX = _robot->getXPos() - lastXPos;
			float deltaY = _robot->getYPos() - lastYPos;
			float deltaYaw = _robot->getYaw() - lastYaw;

			_locMngr->update(deltaX, deltaY, deltaYaw, _robot->getLaserScan());
		}

		_currBeh = _currBeh->selectNext();
		_robot->Read();
	}
}

Manager::~Manager() {
}
