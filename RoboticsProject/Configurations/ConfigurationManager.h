#ifndef CONFIGURATIONMANAGER_H_
#define CONFIGURATIONMANAGER_H_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ConfigurationManager {
private:
	// Hold variables that we got from the parameters file
	string map;
	double mapResolutionCM;
	int gridResolutionCM;
	int xStartLocation;
	int yStartLocation;
	int yawStartLocation;
	int xGoal;
	int yGoal;
	int xSize;
	int ySize;

	// Parameters file strings to search
	const string filePath = "/home/colman/Desktop/parameters.txt";
	const string mapKey = "map:";
	const string mapResolutionCMKey = "MapResolutionCM:";
	const string gridResolutionCMKey = "GridResolutionCM:";
	const string startLocationKey = "startLocation:";
	const string goalKey = "goal:";
	const string robotSizeKey = "robotSize:";

	void readParameters();

public:
	ConfigurationManager();

	void getMapPath(string &mapPath) {
		mapPath = map;
	}

	void getMapResolutionCMKey(double resolution) {
		resolution = mapResolutionCM;
	}

	void getGridResolutionCMKey(int resolution) {
		resolution = gridResolutionCM;
	}

	void getStartLocation(int x, int y, int yaw) {
		x = xStartLocation;
		y = yStartLocation;
		yaw = yawStartLocation;
	}

	void getGoal(int x, int y) {
		x = xGoal;
		y = yGoal;
	}

	void getRobotSize(int x, int y) {
		x = xSize;
		y = ySize;
	}

	~ConfigurationManager();
};

#endif /* CONFIGURATIONMANAGER_H_ */
