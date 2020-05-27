#include <iostream>
#include <list>
#include <queue>
using namespace std;

int main() {
	priority_queue<int> Q;
	list<int> L;
	Q.push(4);
	Q.push(2);
	Q.push(1);
	Q.push(8);
	while (!Q.empty()) {
		L.push_back(Q.top());
		cout << Q.top() << endl;
		Q.pop();
	}
	while (!L.empty()) {
		cout << L.back() << endl;
		L.pop_back();
	}
}
