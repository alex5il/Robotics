#ifndef PLNOBSTACLEAVOID_H_
#define PLNOBSTACLEAVOID_H_

#include "../Behaviours/TurnRight.h"
#include "../Behaviours/TurnLeft.h"
#include "../Behaviours/MoveForward.h"
#include "Plan.h"

class PlnObstacleAvoid: public Plan {
	Behavior* _beh[3];

public:
	PlnObstacleAvoid(Robot* robot);
	Behavior* getStartPoint() {
		return _start;
	}
	virtual ~PlnObstacleAvoid();
};

#endif /* PLNOBSTACLEAVOID_H_ */
