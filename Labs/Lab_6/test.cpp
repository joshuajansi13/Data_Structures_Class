#include <iostream>
#include "LinkedList.h"
#include <stdexcept>

using namespace std;

int main() {
	LinkedList<int>* iLL = NULL;
	iLL = new LinkedList<int>();

	iLL->insertAfter(11, 1);
	iLL->insertTail(10);
	iLL->insertHead(2);
	iLL->insertHead(1);
	iLL->insertTail(3);
	iLL->insertTail(4);
	iLL->insertHead(2);
	iLL->insertTail(5);
	iLL->insertTail(1);
	iLL->insertAfter(6, 5);
	iLL->insertAfter(7, 4);
	iLL->insertAfter(7, 3);
	cout << iLL->at(0) << endl;
	cout << iLL->at(4) << endl;
	cout << iLL->at(2) << endl;
	cout << iLL->size() << endl;
	cout << iLL->toString();

}