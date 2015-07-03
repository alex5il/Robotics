#include "LocalizationManager.h"

LocalizationManager::LocalizationManager(float yaw) {
	srand(time(NULL));
}

void LocalizationManager::init(float yaw) {
	for (unsigned int particle = 0; particle < particlesNum; particle++) {
		int x = rand() % Map::getInstance()->getMapWidth() + 1;
		int y = rand() % Map::getInstance()->getMapHeight() + 1;
		int yaw = DTOR(rand() % 360);

		Particle newParticle(x, y, yaw);
		particles.push_back(newParticle);

		cout << "New particle created at: (" << x << ", " << y << ", " << yaw
				<< ")";
	}
}

void LocalizationManager::update(float delX, float delY, float delYaw,
		float laserScan[]) {
	for (vector<Particle>::iterator particle = particles.begin();
			particle != particles.end(); ++particle) {

		particle->update(delX, delY, delYaw, laserScan);

		if (particle->getBelief() < minBelief) {
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

