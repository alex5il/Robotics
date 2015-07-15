#ifndef WAYPOINT_H_
#define WAYPOINT_H_

#include "../Map/Map.h"

class Waypoint: private Location {

private:
	static const unsigned int radius = 5;

public:
	Waypoint(int x, int y);
	virtual ~Waypoint();
};

#endif /* WAYPOINT_H_ */
