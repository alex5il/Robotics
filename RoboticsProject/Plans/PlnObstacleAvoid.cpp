#include "PlnObstacleAvoid.h"

PlnObstacleAvoid::PlnObstacleAvoid(Robot* robot) :
		Plan(robot) {
	//Creating Behaviors
	_beh[0] = new MoveForward(robot);
	_beh[1] = new TurnLeft(robot);
	_beh[2] = new TurnRight(robot);

	//Connecting Behaviors
	_beh[0]->addBeh(_beh[1]);
	_beh[0]->addBeh(_beh[2]);
	_beh[1]->addBeh(_beh[0]);
	_beh[1]->addBeh(_beh[2]);
	_beh[2]->addBeh(_beh[0]);
	_beh[2]->addBeh(_beh[1]);
	_start = _beh[0];
}

PlnObstacleAvoid::~PlnObstacleAvoid() {
	for (int i = 0; i < 3; i++)
		delete _beh[i];
}
