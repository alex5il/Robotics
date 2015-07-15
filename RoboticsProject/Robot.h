
#ifndef ROBOT_H_
#define ROBOT_H_
#include <libplayerc++/playerc++.h>

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
	double getYPos();
	double getXPos();
	double getYaw();

	virtual ~Robot();
};

#endif /* ROBOT_H_ */
