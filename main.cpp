#include <iostream>
#include <thread>
using namespace std;

#include "trafficlight.h"

int main() {
	trafficLight tf;
	thread lightChange(&trafficLight::changeLight, &tf);
	thread lightprint(&trafficLight::printLight, &tf);

	lightChange.join();
	lightprint.join();

	return 0;
}