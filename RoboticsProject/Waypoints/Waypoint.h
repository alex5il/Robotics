#ifndef WAYPOINT_H_
#define WAYPOINT_H_

#include "../Configurations/Consts.h"
#include "../Map/Map.h"
#include <math.h>

class Waypoint: public Location {

private:
	short radius;

public:
	Waypoint(short x, short y, short radius);

	bool withinRadius(short x, short y);
	float robotAlignment(short x, short y, float yaw);
	short getRadius() {
		return radius;
	}

	virtual ~Waypoint();
};

#endif /* WAYPOINT_H_ */
