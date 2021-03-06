#ifndef CONFIGURATIONMANAGER_H_
#define CONFIGURATIONMANAGER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "Consts.h"

using namespace std;

class ConfigurationManager {

private:
	static ConfigurationManager confMng;

	// Hold variables that we got from the parameters file
	string mapPath;
	float mapResolutionCM;
	int gridResolutionCM;
	int xStartLocation;
	int yStartLocation;
	int yawStartLocation;
	int xGoal;
	int yGoal;
	int xSize;
	int ySize;

	// Parameters file strings to search
	const string filePath = "Configurations/parameters/parameters.txt";
	const string mapKey = "map:";
	const string mapResolutionCMKey = "MapResolutionCM:";
	const string gridResolutionCMKey = "GridResolutionCM:";
	const string startLocationKey = "startLocation:";
	const string goalKey = "goal:";
	const string robotSizeKey = "robotSize:";

	ConfigurationManager();
	void readParameters();
	~ConfigurationManager();

public:
	static string getMapPath() {
		return confMng.mapPath;
	}

	static float getMapResolutionCM() {
		return confMng.mapResolutionCM;
	}

	static int getGridResolutionCM() {
		return confMng.gridResolutionCM;
	}

	static int getStartLocationX() {
		return confMng.xStartLocation;
	}

	static int getStartLocationY() {
		//return mapHeight - confMng.yStartLocation;
		return confMng.yStartLocation;
	}

	static int getStartLocationYaw() {
		return confMng.yawStartLocation;
	}

	static int getGoalX() {
		return confMng.xGoal;
	}

	static int getGoalY() {
		//return mapHeight - confMng.yGoal;
		return confMng.yGoal;
	}

	static int getRobotSizeX() {
		return confMng.xSize;
	}

	static int getRobotSizeY() {
		return confMng.ySize;
	}

	static float positiveModulo(float x, float y) {
		float ret = fmodf(x, y);

		if (ret < 0)
			ret += y;

		return ret;
	}

	static float CoordToMeter(float x) {
		return x / 100 * 2.5;
	}

	static float MeterToCoord(float x) {
		return x / 2.5 * 100;
	}
};

#endif /* CONFIGURATIONMANAGER_H_ */
