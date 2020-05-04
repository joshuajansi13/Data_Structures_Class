#include <iostream>
#include<list>
using namespace std;

void printAll(list<int> intlist) {
	for(list<int>::iterator it = intlist.begin(); it != intlist.end(); it++) {
		cout << *it << endl;
	}
}

int main() {
	list<int> l;
	l.push_back(33);
	l.push_back(22);
	printAll(l);
}
