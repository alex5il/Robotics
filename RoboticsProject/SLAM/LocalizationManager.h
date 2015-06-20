#ifndef LOCALIZATIONMANAGER_H_
#define LOCALIZATIONMANAGER_H_

#include "Particle.h"
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

class LocalizationManager {

private:
	vector<Particle> particles;

	static const unsigned int particlesNum = 100;
	static const double beliefThreshold = 0.5;

public:
	LocalizationManager(double yaw);

	void update(double delX, double delY, double delYaw, double laserScan[]);

	virtual ~LocalizationManager();
};

#endif /* LOCALIZATIONMANAGER_H_ */
