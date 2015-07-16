#include "Robot.h"

Robot::Robot(char* ip, int port) {
	playerClient = new PlayerClient(ip, port);
	posProxy = new Position2dProxy(playerClient);
	lasProxy = new LaserProxy(playerClient);

	posProxy->SetMotorEnable(true);
	//For fixing Player's reading BUG
	for (int i = 0; i < 15; i++)
		Read();
}

void Robot::Read() {
	playerClient->Read();
}

void Robot::setSpeed(float xSpeed, float angularSpeed) {
	posProxy->SetSpeed(xSpeed, angularSpeed);
}

bool Robot::isRightFree() {
	if ((*lasProxy)[50] > 0.5)
		return true;
	else
		return false;
}

bool Robot::isLeftFree() {
	if ((*lasProxy)[50] > 0.5)
		return true;
	else
		return false;
}

bool Robot::isForwardFree() {
	if ((*lasProxy)[332] > 0.5)
		return true;
	else
		return false;
}

float Robot::getXPos() {
	return posProxy->GetXPos();
}

float Robot::getYPos() {
	return posProxy->GetYPos();
}

float Robot::getYaw() {
	return posProxy->GetYaw();
}

float* Robot::getLaserScan() {
	unsigned int samplesCount = lasProxy->GetCount();
	float *scan = new float[samplesCount];

	for (unsigned short i = 0; i < samplesCount; i++) {
		scan[i] = (*lasProxy)[i];
	}

	return scan;
}

Robot::~Robot() {
	delete playerClient;
	delete posProxy;
	delete lasProxy;
}
