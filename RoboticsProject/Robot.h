#ifndef ROBOT_H_
#define ROBOT_H_

#include <libplayerc++/playerc++.h>
#include "Configurations/Consts.h"
#include "Configurations/ConfigurationManager.h"

using namespace PlayerCc;
class Robot {

private:
	PlayerClient* playerClient;
	Position2dProxy* posProxy;
	LaserProxy* lasProxy;

public:
	Robot(char* ip, int port);
	void Read();
	void setSpeed(float xSpeed, float angularSpeed);
	bool isRightFree();
	bool isLeftFree();
	bool isForwardFree();
	float getYPos();
	float getXPos();
	float getYaw();
	float* getLaserScan();
	void setOdometry(float x, float y, float yaw);

	virtual ~Robot();
};

#endif /* ROBOT_H_ */
