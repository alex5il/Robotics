#ifndef WAYPOINT_H_
#define WAYPOINT_H_

#include "../Map/Map.h"
#include <math.h>

class Waypoint: private Location {

private:
	short radius;

public:
	static const unsigned short stdWaypntRadius = 10;
	static const unsigned short fnlWaypntRadius = 10;

	Waypoint(short x, short y, short radius);

	bool withinRadius(short x, short y);

	virtual ~Waypoint();
};

#endif /* WAYPOINT_H_ */
