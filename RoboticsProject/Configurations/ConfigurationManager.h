/*
 * ConfigurationManager.h
 *
 *  Created on: Jun 12, 2015
 *      Author: colman
 */

#ifndef CONFIGURATIONMANAGER_H_
#define CONFIGURATIONMANAGER_H_

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class ConfigurationManager {
private:
	// Hold variables that we got from the parameters file
	string  map;
	double 	mapResolutionCM;
	int 	gridResolutionCM;
	int 	xStartLocation;
	int 	yStartLocation;
	int 	yawStartLocation;
	int 	xGoal;
	int 	yGoal;
	int 	xSize;
	int 	ySize;

	// Parameters file strings to search
	const string mapKey = "map";
	const string mapResolutionCMKey = "MapResolutionCM";
	const string gridResolutionCMKey = "GridResolutionCM";
	const string startLocation = "startLocation";
	const string goal = "goal";
	const string robotSize = "robotSize";

public:
	ConfigurationManager();
	~ConfigurationManager();

	void getMapPath(string &mapPath);
	void getMapResolutionCMKey(double resolution);
	void getGridResolutionCMKey(int resolution);
	void getStartLocation(int x, int y, int yaw);
	void getGoal(int x, int y);
	void getRobotSize(int x, int y);

};

#endif /* CONFIGURATIONMANAGER_H_ */
