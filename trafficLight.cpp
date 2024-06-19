#include <iostream>
#include <mutex>
#include <chrono>

using namespace std;

#include "trafficlight.h"

trafficLight::trafficLight() {
	state = lightState::red;
}

int trafficLight::getLightDuration() {
	switch (state) {
	case lightState::red:
		return 3;
		break;

	case lightState::yellow:
		return 5;
		break;

	case lightState::green:
		return 7;
		break;

	default:
		return 0;
	}
}

string trafficLight::getLightState() {
	switch (state) {
	case lightState::red:
		return "RED";
		break;

	case lightState::yellow:
		return "YELLOW";
		break;

	case lightState::green:
		return "GREEN";
		break;

	default:
		return "RED";
	}
}

trafficLight::lightState trafficLight::getNextState() {
	switch (state)
	{
	case trafficLight::lightState::red:
		return lightState::green;
		break;

	case trafficLight::lightState::yellow:
		return lightState::red;
		break;

	case trafficLight::lightState::green:
		return lightState::yellow;
		break;

	default:
		return lightState::red;
		break;
	}
}

void trafficLight::printLight() {
	while (true) {
		{
			lock_guard<mutex> lock(mtx);
			cout << getLightState() << endl;
		}
		this_thread::sleep_for(chrono::seconds(1));
	}
}


void trafficLight::changeLight() {
	while (true)
	{
		this_thread::sleep_for(chrono::seconds(getLightDuration()));
		{
			lock_guard<mutex> lock(mtx);
			state = getNextState();
			cout<<endl << "Light changed : " << getLightState() << endl<<endl;
		}
	}
}