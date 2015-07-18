#ifndef MOVEFORWARD_H_
#define MOVEFORWARD_H_

#include "Behavior.h"

class MoveForward: public Behavior {

public:
	MoveForward(Robot* robot);

	bool startCond();
	bool stopCond();
	void action();

	virtual ~MoveForward();
};

#endif /* MOVEFORWARD_H_ */
