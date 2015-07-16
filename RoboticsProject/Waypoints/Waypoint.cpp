#include "Waypoint.h"

Waypoint::Waypoint(short x, short y, short radius) {
	this->posX = x;
	this->posY = y;
	this->radius = radius;
}

bool Waypoint::withinRadius(short x, short y) {
	// Calculate distance to the waypoint center.
	float dist = sqrt(pow((this->posX - x), 2) + pow((this->posY - y), 2));

	return (dist <= radius);
}

Waypoint::~Waypoint() {
}
