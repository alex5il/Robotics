#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "../Map/Map.h"
#include "../Configurations/Consts.h"
#include <math.h>
#include <stdlib.h>
#include "../Configurations/Consts.h"

class Particle {

public:
	float x;
	float y;
	float yaw;
	float belief;

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
