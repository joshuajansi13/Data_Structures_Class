#include <iostream>
#include <queue>
using namespace std;

void print(priority_queue<int> q) {
	while(!q.empty()) {
		cout << q.top() << endl;
		q.pop();
	}
}

int main() {
	priority_queue<int> q;
	q.push(4);
	q.push(9);
	q.push(1);
	print(q);
}
