#include "LocalizationManager.h"

LocalizationManager::LocalizationManager(double yaw) {
	srand(time(NULL));

	for (int particle = 0; particle < particlesNum; particle++) {
		Particle newParticle((1 + rand() % 10) + 100 / 2,
				(1 + rand() % 10) + 100 / 2, yaw);
		particles.push_back(newParticle);
	}
}

void LocalizationManager::update(double delX, double delY, double delYaw,
		double laserScan[]) {
	for (vector<Particle>::iterator particle = particles.begin();
			particle != particles.end(); ++particle) {

		particle->update(delX, delY, delYaw, laserScan);

		if (particle->getBelief() < beliefThreshold) {
			particles.erase(particle);
		}

		while (particles.size() < particlesNum) {
			particles.push_back(
					Particle(particles[rand() % particles.size()].x,
							particles[rand() % particles.size()].y,
							particles[rand() % particles.size()].yaw));
		}
	}
}

LocalizationManager::~LocalizationManager() {
}

