#include <vector>
#include <iostream>
using namespace std;

int main() {
	vector<int> vec;
	vec.push_back(20);
	vec.push_back(10);
	vec.push_back(99);
	vec.size(); // 2
	

	for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		cout << *it << endl;
	}
}	

