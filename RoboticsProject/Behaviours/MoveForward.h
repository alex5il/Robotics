#ifndef MOVEFORWARD_H_
#define MOVEFORWARD_H_

#include "Behavior.h"

class MoveForward: public Behavior {

public:
	MoveForward(Robot* robot);

	bool startCond() {
		return _robot->isForwardFree();
	}

	bool stopCond() {
		return !(_robot->isForwardFree());
	}

	void action() {
		_robot->setSpeed(0.3, 0.0);
	}

	virtual ~MoveForward();
};

#endif /* MOVEFORWARD_H_ */
