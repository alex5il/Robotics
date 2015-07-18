#ifndef TURNRIGHT_H_
#define TURNRIGHT_H_

#include "Behavior.h"

class TurnRight: public Behavior {

public:
	TurnRight(Robot* robot);

	bool startCond();
	bool stopCond();
	void action();

	virtual ~TurnRight();
};

#endif /* TURNRIGHT_H_ */
