/*
 * Common.h
 *
 *  Created on: Dec 5, 2014
 *      Author: user
 */

#ifndef COMMON_H_
#define COMMON_H_

#define WORLD_WIDTH 20
#define WORLD_HEIGHT 20
#define MAP_RESOLUTION 0.05
#define MAX_LASER_RANGE 4.095
#define RANGE_ANGLE 120
#define MIN_DIST_ANGLE 0.36
#define SAMPLES_NUM 666
#define MIN_DIST_FROM_OBST 0.8
#define TURN_SPEED 0.5
#define SPEED 0.5
#define NUM_OF_PARTICLES 10
#define THRESHOLD 0.5
#define RADIUS 0.5
#define MAX_YAW M_PI/6


#define MAP_ROWS ((int) (WORLD_HEIGHT/MAP_RESOLUTION))
#define MAP_COLS ((int) (WORLD_WIDTH/MAP_RESOLUTION))
#endif /* COMMON_H_ */
