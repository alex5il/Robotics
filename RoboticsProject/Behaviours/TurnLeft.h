#ifndef TURNLEFT_H_
#define TURNLEFT_H_

#include "Behavior.h"

class TurnLeft: public Behavior {

public:
	TurnLeft(Robot* robot);

	bool startCond() {
		return _robot->isLeftFree();
	}

	bool stopCond() {
		return _robot->isForwardFree();
	}

	void action() {
		_robot->setSpeed(0.0, -angularSpeed);
	}

	virtual ~TurnLeft();
};

#endif /* TURNLEFT_H_ */
