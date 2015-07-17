#ifndef LOCALIZATIONMANAGER_H_
#define LOCALIZATIONMANAGER_H_

#include "Particle.h"
#include "../Map/Map.h"
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class LocalizationManager {

private:
	vector<Particle> particles;

	void init();

public:
	LocalizationManager();

	void update(float delX, float delY, float delYaw, float laserScan[]);
	Particle* estimatedLocation();

	virtual ~LocalizationManager();
};

#endif /* LOCALIZATIONMANAGER_H_ */
