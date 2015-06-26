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
	static const float beliefThreshold = 0.5;
	static const float distance = 5;

	void init(float yaw);

public:
	LocalizationManager(float yaw);

	void update(float delX, float delY, float delYaw, float laserScan[]);

	virtual ~LocalizationManager();
};

#endif /* LOCALIZATIONMANAGER_H_ */
