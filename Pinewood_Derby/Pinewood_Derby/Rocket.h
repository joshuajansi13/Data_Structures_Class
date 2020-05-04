#pragma once
#include "Car.h"


class Rocket: public Car {
	public:
		Rocket(string rocketname, int rocketspeed) :Car(rocketname, rocketspeed) {};
		~Rocket() {};
		int getSpeed() const;
};
