#include "MoveForward.h"

MoveForward::MoveForward(Robot* robot) :
		Behavior(robot) {
}

bool MoveForward::startCond() {
//	return (_robot->isForwardFree()
//			&& (WaypointsManager::getInstance()->isWaypointFront(
//					_robot->getXPos(), _robot->getYPos(), _robot->getYaw())
//					|| (WaypointsManager::getInstance()->isWaypointLeft(
//							_robot->getXPos(), _robot->getYPos(),
//							_robot->getYaw()) && !_robot->isLeftFree())
//					|| (WaypointsManager::getInstance()->isWaypointRight(
//							_robot->getXPos(), _robot->getYPos(),
//							_robot->getYaw()) && !_robot->isRightFree())));

	return (_robot->isForwardFree()
			&& WaypointsManager::getInstance()->isWaypointFront(
					_robot->getXPos(), _robot->getYPos(), _robot->getYaw()));
}

bool MoveForward::stopCond() {
	return !startCond();
}

void MoveForward::action() {
	_robot->setSpeed(forwardSpeed, 0.0);
}

MoveForward::~MoveForward() {
}
