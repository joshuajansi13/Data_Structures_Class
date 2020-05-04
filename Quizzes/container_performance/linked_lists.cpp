#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;


int main() {
	int n = 40000000; // The number of inserts

	// linked lists
	/*list<string> mystrings;
	for (int i = 0; i < n; i++) {
		mystrings.insert(mystrings.end(), "Hello");
	}

	string value;
	for (int i = 0; i < n; i++) {
		list<string>::iterator middle = mystrings.begin();
		advance(middle, n / 2);
		value = *middle;
	}*/


	// vectors
	vector<string> mystrings;
	for (int i = 0; i < n; i++) {
		mystrings.insert(mystrings.end(), "hello");
	}
	string value;
	for (int i = 0; i < n; i++) {
		vector<string>::iterator middle = mystrings.begin();
		advance(middle, n / 2);
		value = *middle;
	}
}