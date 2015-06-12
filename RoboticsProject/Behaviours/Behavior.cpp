#include "Behavior.h"

Behavior::Behavior(Robot* robot) {
	_robot = robot;
}

Behavior::~Behavior() {
	for (iterator it = _behVect.begin(); it != _behVect.end(); ++it)
		delete (*it);
}
