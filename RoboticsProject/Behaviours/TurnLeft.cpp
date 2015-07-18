#include "TurnLeft.h"

TurnLeft::TurnLeft(Robot* robot) :
		Behavior(robot) {
}

bool TurnLeft::startCond() {
	return ((WaypointsManager::getInstance()->isWaypointLeft(_robot->getXPos(),
			_robot->getYPos(), _robot->getYaw()) && _robot->isLeftFree())
			|| (_robot->isLeftFree() && !_robot->isRightFree()));
}

bool TurnLeft::stopCond() {
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

void TurnLeft::action() {
	_robot->setSpeed(0.0, angularSpeed);
}

TurnLeft::~TurnLeft() {
}
