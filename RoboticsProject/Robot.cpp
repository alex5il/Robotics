#include "Robot.h"

Robot::Robot(char* ip, int port) {
	playerClient = new PlayerClient(ip, port);
	posProxy = new Position2dProxy(playerClient);
	lasProxy = new LaserProxy(playerClient);

	float x = ConfigurationManager::CoordToMeter(
			ConfigurationManager::getStartLocationX());
	float y = ConfigurationManager::CoordToMeter(
			Map::getInstance()->getMapHeight()
					- ConfigurationManager::getStartLocationY() + 1);
	float yaw = DTOR(ConfigurationManager::getStartLocationYaw());

	setOdometry(x, y, yaw);

	cout << "Set odometry to: " << "(" << x << ", " << y << ", " << yaw
			<< ")\n";

	setLocation(ConfigurationManager::getStartLocationX(),
			ConfigurationManager::getStartLocationY(), yaw);

	//For fixing Player's reading BUG
	for (int i = 0; i < 15; i++)
		playerClient->Read();

	posProxy->SetMotorEnable(true);

	//For fixing Player's reading BUG
	for (int i = 0; i < 15; i++)
		playerClient->Read();
}

void Robot::Read() {
	//For fixing Player's reading BUG
	for (int i = 0; i < 1; i++)
		playerClient->Read();
}

void Robot::setLocation(float x, float y, float yaw) {
	this->xPos = x;
	this->yPos = y;
	this->yaw = yaw;
}

void Robot::updateLocalization(float x, float y, float yaw) {
	this->xPos = (this->getXPosProxy() + x) / 2;
	this->yPos = (this->getYPosProxy() + y) / 2;
	this->yaw = (this->getYawProxy() + yaw) / 2;
}

void Robot::setSpeed(float xSpeed, float angularSpeed) {
	posProxy->SetSpeed(xSpeed, angularSpeed);
}

bool Robot::isRightFree() {
	if ((*lasProxy)[500] > obstacleDist)
		return true;
	else
		return false;
}

bool Robot::isLeftFree() {
	if ((*lasProxy)[166] > obstacleDist)
		return true;
	else
		return false;
}

bool Robot::isForwardFree() {
	if ((*lasProxy)[332] > obstacleDist)
		return true;
	else
		return false;
}

float Robot::getXPos() {
	return this->xPos;
}

float Robot::getYPos() {
	return this->yPos;
}

float Robot::getYaw() {
	return this->yaw;
}

float* Robot::getLaserScan() {
	unsigned int samplesCount = lasProxy->GetCount();
	float *scan = new float[samplesCount];

	for (unsigned short i = 0; i < samplesCount; i++) {
		scan[i] = (*lasProxy)[i];
	}

	return scan;
}

void Robot::setOdometry(float x, float y, float yaw) {
	double dX = x;
	double dY = y;
	double dYaw = yaw;

	posProxy->GetPose();

	while ((posProxy->GetXPos() != dX) || (posProxy->GetYPos() != dY)
			|| (posProxy->GetYaw() != dYaw)) {
		posProxy->SetOdometry(dX, dY, dYaw);
		Read();
	}
}

float Robot::getXPosProxy() {
	playerClient->Read();
	return ConfigurationManager::MeterToCoord(posProxy->GetXPos());
}

float Robot::getYPosProxy() {
	playerClient->Read();

	float y = Map::getInstance()->getMapHeight()
			- ConfigurationManager::MeterToCoord(posProxy->GetYPos()) + 1;
	return y;
}

float Robot::getYawProxy() {
	playerClient->Read();
	return posProxy->GetYaw();
}

Robot::~Robot() {
	delete playerClient;
	delete posProxy;
	delete lasProxy;
}
