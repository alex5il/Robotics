#ifndef BEHAVIOR_H_
#define BEHAVIOR_H_

#include <vector>
#include "../Configurations/Consts.h"
#include "../Robot.h"
#include "../Waypoints/WaypointsManager.h"

using namespace std;

class Behavior {

private:
	vector<Behavior*> _behVect;

protected:
	Robot* _robot;

public:
	Behavior(Robot* robot);

	virtual ~Behavior();

	virtual bool startCond() = 0;
	virtual bool stopCond() = 0;
	virtual void action() = 0;

	void addBeh(Behavior* next) {
		_behVect.push_back(next);
	}

	Behavior* selectNext() {
		//Run over vector and return first true
		//startCond of the first behavior
		for (unsigned int i = 0; i < _behVect.size(); i++)
			if (_behVect[i]->startCond())
				return _behVect[i];

		return NULL;
	}

};

#endif /* BEHAVIOR_H_ */
