#include <iostream>
#include <fstream>
#include <string>
#include "TodoList.h"

using namespace std;


int main(int argc, char *argv[]) {
	TodoList myList;

	/*for (int i = 0; i < argc; i++) {
		cout << "argv[" << i << "]=" << argv[i] << endl;
	}*/

	string firstarg = argv[1];

	if (firstarg.compare("add") == 0) {
		string date = argv[2];
		string task = argv[3];
		myList.add(date, task);
	}
	else if (firstarg.compare("remove") == 0) {
		string task = argv[2];
		myList.remove(task);
	}
	else if (firstarg.compare("printList") == 0) {
		myList.printTodoList();
	}
	else if (firstarg.compare("printDay") == 0) {
		string date = argv[2];
		myList.printDaysTasks(date);
	}

	return 0;
}