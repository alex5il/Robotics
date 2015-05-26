/*
 * Manager.h
 *
 *  Created on: May 26, 2015
 *      Author: user
 */

#ifndef MANAGER_H_
#define MANAGER_H_
#include "Plans/PlnObstacleAvoid.h"
#include "Robot.h"

class Manager {
	Behavior* _curr;
	Robot* _robot;
public:
	Manager(Robot* robot, Plan* pln);
	void run();
	virtual ~Manager();
};

#endif /* MANAGER_H_ */
