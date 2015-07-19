#include "TurnRight.h"

TurnRight::TurnRight(Robot* robot) :
		Behavior(robot) {
}

bool TurnRight::startCond() {
	bool startCond;

	startCond = true;

//	startCond = (WaypointsManager::getInstance()->isWaypointRight(
//			_robot->getXPos(), _robot->getYPos(), _robot->getYaw()));

	std::cout << "Start condition for MoveRight is " << startCond << "\n";

	return startCond;
}

bool TurnRight::stopCond() {
	bool stopCond;

//	stopCond = ((_robot->isForwardFree()
//			&& (WaypointsManager::getInstance()->isWaypointFront(
//					_robot->getXPos(), _robot->getYPos(), _robot->getYaw())
//					|| (WaypointsManager::getInstance()->isWaypointLeft(
//							_robot->getXPos(), _robot->getYPos(),
//							_robot->getYaw()) && !_robot->isLeftFree())
//					|| (WaypointsManager::getInstance()->isWaypointRight(
//							_robot->getXPos(), _robot->getYPos(),
//							_robot->getYaw()) && !_robot->isRightFree())))
//			|| (WaypointsManager::getInstance()->isWaypointLeft(
//					_robot->getXPos(), _robot->getYPos(), _robot->getYaw())));

//	stopCond = !startCond();

	stopCond = (_robot->isForwardFree()
			&& WaypointsManager::getInstance()->isWaypointFront(
					_robot->getXPos(), _robot->getYPos(), _robot->getYaw()));

	std::cout << "Stop condition for MoveRight is " << stopCond << "\n";

	return stopCond;
}

void TurnRight::action() {
	std::cout << "Starting moving right. " << "\n";
	_robot->setSpeed(0.0, -angularSpeed);
}

TurnRight::~TurnRight() {
}
