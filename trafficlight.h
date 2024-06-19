#pragma once
#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <iostream>
#include <mutex>
using namespace std;

class trafficLight {
private:
	enum class lightState {red, yellow, green};
	lightState state;

	mutex mtx;

	int getLightDuration();
	lightState getNextState();
	string getLightState();

public:
	trafficLight();
	void changeLight();
	void printLight();
};

#endif 
