#include "Pathfinder.h"

string Pathfinder::toString() const {
	stringstream ss;
	for (int row = 0; row < ROW_SIZE; row++) {
		for (int col = 0; col < COL_SIZE; col++) {
			ss << maze_grid[row][col];
		}
		ss << endl;
	}
	return ss.str();
}

void Pathfinder::createRandomMaze() {

}

bool Pathfinder::importMaze(string file_name) {
	cout << "importMaze from " << file_name << endl;
	ifstream file(file_name.c_str());
	if (file.is_open()) {
		string line;
		int row_count = 0;
		for (int row = 0; row < ROW_SIZE; row++) {
			getline(file, line);
			stringstream ss(line);
			for (int col = 0; col < COL_SIZE; col++) {
				int value;
				ss >> value;
				cout << "[" << row << "][" << col << "]=" << value << endl;
				maze_grid[row][col] = value;
			}
		}
	}
	return true;
}

bool Pathfinder::find_maze_path(int grid[ROW_SIZE][COL_SIZE], int r, int c) {
	cout << "find_maze_path [" << r << "][" << c << "]" << endl;
	cout << this->toString();
	if (r < 0 || c < 0 || r >= ROW_SIZE || c >= COL_SIZE) {
		return false;      // Cell is out of bounds.
	}
	else if (grid[r][c] != BACKGROUND) {
		return false;      // Cell is on barrier or dead end.
	}
	else if (r == ROW_SIZE - 1 && c == COL_SIZE - 1) {
		grid[r][c] = PATH;         // Cell is on path
		solution.push_back("(" + to_string(r) + "," + to_string(c) + ")");
		return true;               // and is maze exit.
	}
	else {
		// Recursive case.
		// Attempt to find a path from each neighbor.
		// Tentatively mark cell as on path.
		grid[r][c] = PATH;
		if (find_maze_path(grid, r - 1, c) // Up
			|| find_maze_path(grid, r + 1, c) // Down
			|| find_maze_path(grid, r, c - 1) // Left
			|| find_maze_path(grid, r, c + 1)) { // Right
			solution.push_back("(" + to_string(r) + "," + to_string(c) + ")");
			return true;
		}
		else {
			grid[r][c] = TEMPORARY;  // Dead end.
			return false;
		}
	}
}

vector<string> Pathfinder::solveMaze() {
	find_maze_path(maze_grid, 0, 0);
	for (auto s : solution) {
		cout << s << endl;
	}
	return solution;
}