#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <math.h>

class Particle {

public:
	float x;
	float y;
	float yaw;
	float belief;

	float calcProbability(float delX, float delY, float delYaw);
	float updateMap(float laserScan[]);

	Particle(float x, float y, float yaw);
	void update(float delX, float delY, float delYaw, float laserScan[]);

	float getBelief() {
		return belief;
	}

	virtual ~Particle();
};

#endif /* PARTICLE_H_ */
