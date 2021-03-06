#ifndef PLAN_H_
#define PLAN_H_

#include "../Behaviours/Behavior.h"
#include "../Robot.h"

class Plan {

protected:
	Behavior* _start;

public:
	Plan(Robot* robot);

	virtual Behavior* getStartPoint() {
		return _start;
	}

	virtual ~Plan();
};

#endif /* PLAN_H_ */
