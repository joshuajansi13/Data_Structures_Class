#pragma once
#include "CarInterface.h"


class Car : public CarInterface {
	public:
		Car(string myname, int myspeed) {
			cout << "In Car Constructor" << endl;
			name = myname;
			speed = myspeed;
		};
		~Car() {}

		string getName() const; // Returns the name of this car
		virtual int getSpeed() const = 0; // Returns the speed of this car

	protected:
		string name;
		int speed;
};
