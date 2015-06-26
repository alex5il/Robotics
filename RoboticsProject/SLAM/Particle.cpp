#include "Particle.h"

Particle::Particle(float x, float y, float yaw) {
	this->x = x;
	this->y = y;
	this->yaw = yaw;
	this->belief = 1.0;
}

void Particle::update(float delX, float delY, float delYaw, float laserScan[]) {
	x += (delX * 100);
	y += (delY * 100);
	yaw += delYaw;

	float predictBelief = belief * calcProbability(delX, delY, delYaw);
	belief = predictBelief * updateMap(laserScan);
}

float Particle::calcProbability(float delX, float delY, float delYaw) {
	float distance = sqrt(pow(delX, 2) + pow(delY, 2));

	if ((delYaw < 0.5/*normal accurate angle*/) && (delYaw > -0.5)) {
		if (distance <= 0.3/*Safe distance to move*/)
			return 1.0;
		else
			return (0.3/*safe distance*/+ distance + 0.2);
	} else if ((delYaw < 1.0/*Max accurate angle to move*/)
			&& (delYaw > -1.0)) {
		if (distance <= 0.3)
			return 1.0;
		else
			return (0.3 + distance - 0.2);
	}
	return 1.0;
}

float Particle::updateMap(float laserScan[]) {
	return 1.0;
}

Particle::~Particle() {
}

