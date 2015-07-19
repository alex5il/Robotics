#include "MoveForward.h"

MoveForward::MoveForward(Robot* robot) :
		Behavior(robot) {
}

bool MoveForward::startCond() {
	bool startCond;

//	startCond = (_robot->isForwardFree()
//			&& (WaypointsManager::getInstance()->isWaypointFront(
//					_robot->getXPos(), _robot->getYPos(), _robot->getYaw())
//					|| (WaypointsManager::getInstance()->isWaypointLeft(
//							_robot->getXPos(), _robot->getYPos(),
//							_robot->getYaw()) && !_robot->isLeftFree())
//					|| (WaypointsManager::getInstance()->isWaypointRight(
//							_robot->getXPos(), _robot->getYPos(),
//							_robot->getYaw()) && !_robot->isRightFree())));

	startCond = (_robot->isForwardFree()
			&& WaypointsManager::getInstance()->isWaypointFront(
					_robot->getXPos(), _robot->getYPos(), _robot->getYaw()));

	std::cout << "Start condition for MoveForward is " << startCond << "\n";

	return startCond;
}

bool MoveForward::stopCond() {
	bool stopCond;

	stopCond = !startCond();

	std::cout << "Stop condition for MoveForward is " << stopCond << "\n";

	return stopCond;
}

void MoveForward::action() {
	std::cout << "Starting moving forward. " << "\n";
	_robot->setSpeed(forwardSpeed, 0.0);
}

MoveForward::~MoveForward() {
}
