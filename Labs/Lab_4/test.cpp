#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Pathfinder.h"

int main() {

	Pathfinder* pathptr = NULL;//the Pathfinder
	// Test 2D array
	pathptr = new Pathfinder();
	if (pathptr->importMaze("Mazes/Solvable1.txt")) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
	cout << pathptr->toString();
	pathptr->solveMaze();
	exit(0);
	// End of Test 3D array

}