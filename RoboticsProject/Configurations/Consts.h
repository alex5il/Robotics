#ifndef CONSTS_H_
#define CONSTS_H_

#include <libplayercore/playercommon.h>
#include <math.h>

static const unsigned int COLOR_WHITE = 255;
static const unsigned int COLOR_BLACK = 0;
static const unsigned int LASER_SAMPLES = 666;
static const unsigned int LASER_RANGE = 4;
static const float LASER_AREA = 0.36;
static const unsigned int LASER_RESOLUTION = 240;
static const float forwardSpeed = 0.3;
static const float angularSpeed = 0.3;
static const float obstacleDist = 0.7;

// Particles
static const unsigned int particlesNum = 60;
static const float minBelief = 0.3;

static const int childRadius = 0;
static const float childlYawRange = 1;
static const float beliefFactor = 1.2;

static const float lowYaw = 1.0;
static const float lowYawProb = 1.0;
static const float highYaw = 3.0;
static const float highYawProb = 0.85;
static const float maxYawProb = 0.7;

static const float lowDistance = 8;
static const float lowDistanceProb = 1.0;
static const float highDistance = 40;
static const float highDistanceProb = 0.85;
static const float maxDistanceProb = 0.7;

// Waypoints
static const unsigned short stdWaypntRadius = 15;
static const unsigned short fnlWaypntRadius = 4;
static const float waypointAlignment = 20;

#endif /* CONSTS_H_ */
