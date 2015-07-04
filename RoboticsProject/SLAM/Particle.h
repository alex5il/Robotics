#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "../Map/Map.h"
#include "../Configurations/Consts.h"
#include <math.h>
#include <stdlib.h>

class Particle {

public:
	float x;
	float y;
	float yaw;
	float belief;

	static const unsigned int childRadius = 5;
	static const unsigned int childlYawRange = 45;
	static const float beliefFactor = 1.0;

	static const float lowYaw = 1.0;
	static const float lowYawProb = 1.0;
	static const float highYaw = 3.0;
	static const float highYawProb = 0.85;
	static const float maxYawProb = 0.7;

	static const float lowDistance = 10.0;
	static const float lowDistanceProb = 1.0;
	static const float highDistance = 20.0;
	static const float highDistanceProb = 0.85;
	static const float maxDistanceProb = 0.7;

	Particle(float x, float y, float yaw);

	bool operator<(const Particle& p) const;

	void update(float delX, float delY, float delYaw, float laserScan[]);
	Particle createChild();
	float probabilityByMove(float delX, float delY, float delYaw);
	float probabilityByMap(float laserScan[]);

	float getBelief() {
		return belief;
	}

	virtual ~Particle();
};

#endif /* PARTICLE_H_ */
