/*
 * main.cpp
 *
 *  Created on: May 22, 2015
 *      Author: user
 */

#include <libplayerc++/playerc++.h>

using namespace PlayerCc;

int main() {
	/*PlayerClient pc("10.10.245.65", 6665);*/
	PlayerClient pc("localhost", 6665);
	LaserProxy lp(&pc);
	Position2dProxy pp(&pc);

	pp.SetMotorEnable(true);
	while (true) {
		pc.Read();

		double d1 = 10;
		double d2 = 10;

		if (lp[333] < 1.8){
			for(int i = 50; i<=333;i++){
				if (lp[i] < d1){
					d1 = lp[i];
				}
				if (lp[666 - i] < d2){
					d2 = lp[666 - i];
				}
			}

			if (d1 > d2){
				pp.SetSpeed(0.0, -0.3);
			}
			else {
				pp.SetSpeed(0.0, 0.3);
			}

		}
		else{
			pp.SetSpeed(0.8, 0.0);
		}

	}
	return 0;

}
