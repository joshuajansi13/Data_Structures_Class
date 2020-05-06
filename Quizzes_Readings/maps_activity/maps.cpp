#include <iostream>
#include <map>
#include <string>
#include "print.h"
using namespace std;


int main() {
	map<string, int> age;

	age["Mark"] = 16;
	age["John"] = 15;
	age["Mary"] = 17;
	age["Jane"] = 16;

	print(age);

	age.erase("Mary");

	print(age);

	cout << age["John"] << endl;
	cout << age["Mary"] << endl;

	print(age);
}