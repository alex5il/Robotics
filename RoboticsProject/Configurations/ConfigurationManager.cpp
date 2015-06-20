#include "ConfigurationManager.h"

ConfigurationManager::ConfigurationManager() {
	readParameters();
}

void ConfigurationManager::readParameters() {
	ifstream paramFile(filePath.c_str());
	string paramName, paramVal;

	if (paramFile.is_open()) {
		while (paramFile >> paramName) {
			if (paramName == mapKey)
				paramFile >> map;
			else if (paramName == mapResolutionCMKey)
				paramFile >> mapResolutionCM;
			else if (paramName == gridResolutionCMKey)
				paramFile >> gridResolutionCM;
			else if (paramName == startLocationKey)
				paramFile >> xStartLocation >> yStartLocation
						>> yawStartLocation;
			else if (paramName == goalKey)
				paramFile >> xGoal >> yGoal;
			else if (paramName == robotSizeKey)
				paramFile >> xSize >> ySize;
		}
		paramFile.close();
	}
}

ConfigurationManager::~ConfigurationManager() {
}
