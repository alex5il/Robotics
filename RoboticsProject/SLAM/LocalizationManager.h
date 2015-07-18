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
	static LocalizationManager* Instance;
	vector<Particle> particles;

	void init();
	LocalizationManager();
	virtual ~LocalizationManager();

public:
	static LocalizationManager* getInstance();
	void update(float delX, float delY, float delYaw, float laserScan[]);
	Particle* estimatedLocation();
	static void deleteInstance();
};

#endif /* LOCALIZATIONMANAGER_H_ */
