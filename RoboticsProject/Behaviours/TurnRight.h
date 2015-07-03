#ifndef TURNRIGHT_H_
#define TURNRIGHT_H_

#include "Behavior.h"

class TurnRight: public Behavior {

public:
	TurnRight(Robot* robot);

	bool startCond() {
		return _robot->isRightFree();
	}

	bool stopCond() {
		return _robot->isForwardFree();
	}

	void action() {
		_robot->setSpeed(0.0, 0.3);
	}

	virtual ~TurnRight();
};

#endif /* TURNRIGHT_H_ */
