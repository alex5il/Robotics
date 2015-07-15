#include "Particle.h"

bool Particle::operator<(const Particle& p) const {
	return (belief < p.belief);
}

Particle::Particle(float x, float y, float yaw) {
	this->x = x;
	this->y = y;
	this->yaw = yaw;
	this->belief = 1.0;
}

void Particle::update(float delX, float delY, float delYaw, float laserScan[]) {
	x += delX;
	y += delY;
	yaw += delYaw;

	float predBelief = belief * probabilityByMove(delX, delY, delYaw);
	belief = beliefFactor * predBelief * probabilityByMap(laserScan);
}

Particle Particle::createChild() {
	return Particle(this->x + childRadius - (rand() % (2 * childRadius)),
			this->x + childRadius - (rand() % (2 * childRadius)),
			fmod(
					this->yaw
							+ DTOR(
									childlYawRange
											- rand() % (2 * childlYawRange)),
					2 * M_PI));
}

float Particle::probabilityByMove(float delX, float delY, float delYaw) {
	float distance = sqrt(pow(delX, 2) + pow(delY, 2));
	float yawProb, distProb;

	// Calculating yaw probability.
	if (abs(delYaw) <= lowYaw) {
		yawProb = lowYawProb;
	} else if (abs(delYaw) <= highYaw) {
		yawProb = highYawProb;
	} else {
		yawProb = maxYawProb;
	}

	// Calculating distance probability.
	if (distance <= lowDistance) {
		distProb = lowDistanceProb;
	} else if (distance <= highDistance) {
		distProb = highDistanceProb;
	} else {
		distProb = maxDistanceProb;
	}

	// The final probability.
	return yawProb * distProb;
}

float Particle::probabilityByMap(float laserScan[]) {
	float misses = 0;
	float total = 0;

	// If the particle is outside of the map - return 0 probability.
	if ((this->x > Map::getInstance()->getMapWidth() || this->x < 0)
			|| (this->y > Map::getInstance()->getMapHeight() || this->y < 0)) {

		return 0;
	}

	// Check if the particle is not on an occupied cell.
	if (Map::getInstance()->getGrid()[x][y] == OCCUPIED_CELL) {
		return 0;
	}

	// Check every laser scan.
	for (unsigned int i = 0; i < LASER_SAMPLES; i++) {

		float laserAngle = (i * LASER_AREA) - 360 + LASER_RESOLUTION;

		// For every free cell in the laser scan.
		for (int j = 0; j < laserScan[i] - 1; j++) {

			int xPos = this->x + sin(DTOR(laserAngle) + this->yaw) * j;
			int yPos = this->y + cos(DTOR(laserAngle) + this->yaw) * j;

			// If the cell is out of bounds or is occupied - increment the misses.
			if ((xPos > Map::getInstance()->getMapWidth() || xPos < 0)
					|| (yPos > Map::getInstance()->getMapHeight() || yPos < 0)
					|| Map::getInstance()->getGrid()[xPos][yPos]
							== OCCUPIED_CELL) {
				misses++;
			}

			total++;
		}

		// If obstacle detected.
		if (laserScan[i] < LASER_RANGE) {

			int xPos = this->x
					+ sin(DTOR(laserAngle) + this->yaw) * laserScan[i];
			int yPos = this->y
					+ cos(DTOR(laserAngle) + this->yaw) * laserScan[i];

			// If the cell is out of bounds or is free - increment the misses.
			if ((xPos > Map::getInstance()->getMapWidth() || xPos < 0)
					|| (yPos > Map::getInstance()->getMapHeight() || yPos < 0)
					|| Map::getInstance()->getGrid()[xPos][yPos] == FREE_CELL) {
				misses++;
			}

			total++;
		}
	}

	return total / misses;
}

Particle::~Particle() {
}

