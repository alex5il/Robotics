#include "TurnRight.h"

TurnRight::TurnRight(Robot* robot) :
		Behavior(robot) {
}

bool TurnRight::startCond() {
	return true;
}

bool TurnRight::stopCond() {
	return (_robot->isForwardFree()
			&& (WaypointsManager::getInstance()->isWaypointFront(
					_robot->getXPos(), _robot->getYPos(), _robot->getYaw())
					|| (WaypointsManager::getInstance()->isWaypointLeft(
							_robot->getXPos(), _robot->getYPos(),
							_robot->getYaw()) && !_robot->isLeftFree())
					|| (WaypointsManager::getInstance()->isWaypointRight(
							_robot->getXPos(), _robot->getYPos(),
							_robot->getYaw()) && !_robot->isRightFree())));
}

void TurnRight::action() {
	_robot->setSpeed(0.0, -angularSpeed);
}

TurnRight::~TurnRight() {
}
