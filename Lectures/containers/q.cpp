#include <queue>
#include <iostream>
using namespace std;

void print(queue<int> q) {
	while(!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}
}

int main() {
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	print(q);

	q.front();
	q.pop();

	q.push(4);
	q.push(5);
	print(q);
}
