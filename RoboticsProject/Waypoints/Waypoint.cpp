#include "Waypoint.h"

Waypoint::Waypoint(short x, short y, short radius) {
	this->posX = x;
	this->posY = y;
	this->radius = radius;
}

float Waypoint::robotAlignment(short x, short y, float yaw) {
	// Calculate the degree of line from the robot to the waypoint.
	float theta = ConfigurationManager::positiveModulo(
			RTOD(atan2(y - this->posY, this->posX - x)), 360);
	float robotAngle = ConfigurationManager::positiveModulo(RTOD(yaw), 360);

	cout << "\n\nTheta is " << theta << "\n";
	cout << "Robot angle is " << robotAngle << "\n";
	cout << "Difference is " << robotAngle - theta << "\n";

	return robotAngle - theta;
}

bool Waypoint::withinRadius(short x, short y) {
	// Calculate distance to the waypoint center.
	float dist = sqrt(pow((this->posX - x), 2) + pow((this->posY - y), 2));

	cout << "\n\nWaypoint is at: (" << this->posX << ", " << this->posY
			<< ")\n";
	cout << "Distance from waypoint is: " << dist << "\n";

	return (dist <= radius);
}

Waypoint::~Waypoint() {
}
