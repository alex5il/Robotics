#ifndef ROBOT_H_
#define ROBOT_H_

#include <libplayerc++/playerc++.h>
#include "Configurations/Consts.h"
#include "Configurations/ConfigurationManager.h"
#include "Map/Map.h"

using namespace PlayerCc;

class Robot {

private:
	PlayerClient* playerClient;
	Position2dProxy* posProxy;
	LaserProxy* lasProxy;

public:
	float xPos;
	float yPos;
	float yaw;

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
	void setLocation(float x, float y, float yaw);
	float getXPosProxy();
	float getYPosProxy();
	float getYawProxy();

	virtual ~Robot();
};

#endif /* ROBOT_H_ */
