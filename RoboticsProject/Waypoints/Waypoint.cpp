#include "Waypoint.h"

Waypoint::Waypoint(short x, short y, short radius) {
	this->posX = x;
	this->posY = y;
	this->radius = radius;
}

float Waypoint::robotAlignment(short x, short y, float yaw) {
	// Calculate the degree of line from the robot to the waypoint.
	float theta = fmod(RTOD(atan2(this->posY - y, this->posX - x)), 360);
	float robotAngle = fmod(RTOD(yaw), 360);

	return robotAngle - theta;
}

bool Waypoint::withinRadius(short x, short y) {
	// Calculate distance to the waypoint center.
	float dist = sqrt(pow((this->posX - x), 2) + pow((this->posY - y), 2));

	return (dist <= radius);
}

Waypoint::~Waypoint() {
}
