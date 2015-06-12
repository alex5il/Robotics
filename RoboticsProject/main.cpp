/*
 * main.cpp
 *
 *  Created on: May 22, 2015
 *      Author: user
 */

#include "Robot.h"
#include "Manager.h"
#include "Plans/PlnObstacleAvoid.h"
int main()
{
	Robot robot("localhost",6665);
	PlnObstacleAvoid plnOA(&robot);
	Manager manager(&robot, &plnOA);
	manager.run();


	// Oded

}
