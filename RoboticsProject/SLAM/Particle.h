#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <math.h>

class Particle {

public:
	double x;
	double y;
	double yaw;
	double belief;

	double calcProbability(double delX, double delY, double delYaw);
	double updateMap(double laserScan[]);

	Particle(double x, double y, double yaw);
	void update(double delX, double delY, double delYaw, double laserScan[]);

	double getBelief() {
		return belief;
	}

	virtual ~Particle();
};

#endif /* PARTICLE_H_ */
