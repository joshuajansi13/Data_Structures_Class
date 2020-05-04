#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {
	vector<string> mystrings;
	int n = 40000; // The number of inserts 
	// inserting in front of vector
	/*for (int i = 0; i < n; i++) {
		mystrings.insert(mystrings.begin(), "Hello");
	}*/
	// inserting in back of vector
	for (int i = 0; i < n; i++) {
		mystrings.insert(mystrings.end(), "Hello");
	}
	return 0;
}