#include "TurnLeft.h"

TurnLeft::TurnLeft(Robot* robot) :
		Behavior(robot) {
}

bool TurnLeft::startCond() {
	bool startCond;

//	startCond = ((WaypointsManager::getInstance()->isWaypointLeft(
//			_robot->getXPos(), _robot->getYPos(), _robot->getYaw())
//			&& _robot->isLeftFree())
//			|| (_robot->isLeftFree() && !_robot->isRightFree()));

	startCond = (WaypointsManager::getInstance()->isWaypointLeft(
			_robot->getXPos(), _robot->getYPos(), _robot->getYaw()));

	std::cout << "Start condition for MoveLeft is " << startCond << "\n";

	return startCond;
}

bool TurnLeft::stopCond() {
	bool stopCond;

//	stopCond = (_robot->isForwardFree()
//			&& (WaypointsManager::getInstance()->isWaypointFront(
//					_robot->getXPos(), _robot->getYPos(), _robot->getYaw())
//					|| (WaypointsManager::getInstance()->isWaypointLeft(
//							_robot->getXPos(), _robot->getYPos(),
//							_robot->getYaw()) && !_robot->isLeftFree())
//					|| (WaypointsManager::getInstance()->isWaypointRight(
//							_robot->getXPos(), _robot->getYPos(),
//							_robot->getYaw()) && !_robot->isRightFree())));

//	stopCond = !startCond();

	stopCond = (_robot->isForwardFree()
			&& WaypointsManager::getInstance()->isWaypointFront(
					_robot->getXPos(), _robot->getYPos(), _robot->getYaw()));

	std::cout << "Stop condition for MoveLeft is " << stopCond << "\n";

	return !startCond();
}

void TurnLeft::action() {
	std::cout << "Starting moving left. " << "\n";
	_robot->setSpeed(0.0, angularSpeed);
}

TurnLeft::~TurnLeft() {
}
