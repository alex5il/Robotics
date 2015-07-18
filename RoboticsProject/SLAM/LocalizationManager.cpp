#include "LocalizationManager.h"

LocalizationManager* LocalizationManager::Instance = NULL;

LocalizationManager::LocalizationManager() {
	srand(time(NULL));
	init();
}

void LocalizationManager::init() {
	for (unsigned int particle = 0; particle < particlesNum; particle++) {
		float x = ConfigurationManager::getStartLocationX() + childRadius
				- (rand() % (2 * childRadius));
		float y = ConfigurationManager::getStartLocationY() + childRadius
				- (rand() % (2 * childRadius));
		float yaw = ConfigurationManager::positiveModulo(
				ConfigurationManager::getStartLocationYaw()
						+ childlYawRange- DTOR(rand() % (2 * childlYawRange)),
				2 * M_PI);

		Particle newParticle(x, y, yaw);
		particles.push_back(newParticle);

		cout << "New particle created at: (" << x << ", " << y << ", " << yaw
				<< ")";
	}
}

void LocalizationManager::update(float delX, float delY, float delYaw,
		float laserScan[]) {
	vector<int> particlesToRemove;

	// Looping at all the particles and updating them.
	for (unsigned int i = 0; i < particles.size(); i++) {
		particles[i].update(delX, delY, delYaw, laserScan);

		if (particles[i].getBelief() < minBelief) {
			particlesToRemove.push_back(i);
		}
	}

	// Removing the untrustworthy particles.
	if (particlesToRemove.size() > 0) {
		for (int i = particlesToRemove.size() - 1; i >= 0; i--) {
			particles.erase(particles.begin() + particlesToRemove[i]);
		}
	}

	// Sorting particles to clone those with highest belief.
	std::sort(particles.begin(), particles.end());

	// If need to create new particles.
	if (particles.size() < particlesNum) {
		// How many children to create for each particle.
		short childrenToCreate = floor(particlesNum / particles.size());

		// Looping at all the particles from highest belief to lowest and creating new children.
		for (unsigned int i = 0;
				(particles.size() + childrenToCreate) < particlesNum; i++) {
			for (int j = 0; j < childrenToCreate; j++) {
				particles.push_back(particles[i].createChild());
			}
		}
	}
}

Particle* LocalizationManager::estimatedLocation() {
	float maxBelief = 0;
	Particle* bestParticle = NULL;

	for (unsigned int i = 0; i < particles.size(); i++) {
		if (particles[i].getBelief() > maxBelief) {
			maxBelief = particles[i].belief;
			bestParticle = &particles[i];
		}
	}

	return bestParticle;
}

LocalizationManager* LocalizationManager::getInstance() {
	if (!Instance) {
		Instance = new LocalizationManager();
	}

	return Instance;
}

void LocalizationManager::deleteInstance() {
	delete Instance;
}

LocalizationManager::~LocalizationManager() {
}
