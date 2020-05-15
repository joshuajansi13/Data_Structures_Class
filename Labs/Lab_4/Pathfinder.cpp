#include "Pathfinder.h"

Pathfinder::Pathfinder() { // constructor
	srand(time(NULL));
	for (int level = 0; level < LEVEL_SIZE; level++) {
		for (int row = 0; row < ROW_SIZE; row++) {
			for (int col = 0; col < COL_SIZE; col++) {
				maze_grid[row][col][level] = 1;
			}
		}
	}
}

string Pathfinder::toString() const {
	stringstream ss;
	for (int level = 0; level < LEVEL_SIZE; level++) {
		for (int row = 0; row < ROW_SIZE; row++) {
			for (int col = 0; col < COL_SIZE; col++) {
				if (col != COL_SIZE - 1) { // to match keyfile
					ss << maze_grid[row][col][level] << " ";
				}
				else {
					ss << maze_grid[row][col][level];
				}
			}
			ss << endl;
		}
		if (level != LEVEL_SIZE - 1) { // to match keyfile
			ss << endl;
		}
	}
	return ss.str();
}

void Pathfinder::createRandomMaze() {
	//cout << "Creating random maze:" << endl;
	for (int row = 0; row < ROW_SIZE; row++) {
		for (int col = 0; col < COL_SIZE; col++) {
			for (int level = 0; level < LEVEL_SIZE; level++) {
				maze_grid[row][col][level] = rand() % 2; // runs 125 times
			}
		}
	}
	maze_grid[0][0][0] = 1;
	maze_grid[4][4][4] = 1;
	//cout << this->toString();
}

bool Pathfinder::importMaze(string file_name) {
	cout << "importMaze from " << file_name << endl;
	ifstream file(file_name.c_str());
	int temp_maze[ROW_SIZE][COL_SIZE][LEVEL_SIZE];
	if (file.is_open()) { // checks to see if file is valid
		string line;
		//int row_count = 0;
		for (int level = 0; level < LEVEL_SIZE; level++) {
			for (int row = 0; row < ROW_SIZE; row++) {
				if (file.eof()) { // this will take care of size of 3D array
					return false;
				}
				getline(file, line);
				if (line.size() == 0) {
					getline(file, line);
				}
				stringstream ss(line);
				for (int col = 0; col < COL_SIZE; col++) {
					int value;
					if (!(ss >> value)) {
						return false;
					}
					//cout << value << endl;
					//cout << "[" << row << "][" << col << "][" << level << "]=" << value << endl;
					if (value != 0 && value != 1) {
						return false;
					}
					else {
						temp_maze[row][col][level] = value;
					}
				}
			}
		}
		if (!file.eof()) { // this will take care of size of 3D array
			return false;
		}
		if (temp_maze[0][0][0] != 1 || temp_maze[4][4][4] != 1) { // check to see if first and last input are valid
			return false;
		}
	}
	else {
		return false;
	}

	for (int level = 0; level < LEVEL_SIZE; level++) {
		for (int row = 0; row < ROW_SIZE; row++) {
			for (int col = 0; col < COL_SIZE; col++) {
				maze_grid[row][col][level] = temp_maze[row][col][level];
			}
		}
	}
	return true;
}

bool Pathfinder::find_maze_path(int grid[ROW_SIZE][COL_SIZE][LEVEL_SIZE], int r, int c, int l) {
	solution.push_back("(" + to_string(c) + ", " + to_string(r) + ", " + to_string(l) + ")");
	// Base Cases
	if (r < 0 || c < 0 || l < 0 || r >= ROW_SIZE || c >= COL_SIZE || l >= LEVEL_SIZE || grid[r][c][l] != BACKGROUND) {
		solution.pop_back();
		return false;      // Cell is out of bounds, wall, or visited
	}
	if (r == ROW_SIZE - 1 && c == COL_SIZE - 1 && l == LEVEL_SIZE - 1) { // end of maze
		return true;               // and is maze exit.
	}
	// Recursive case.
	// Attempt to find a path from each neighbor.
	// Tentatively mark cell as on path.
	grid[r][c][l] = PATH; // cell is on path
	if (find_maze_path(grid, r - 1, c, l) // in
		|| find_maze_path(grid, r + 1, c, l) // out
		|| find_maze_path(grid, r, c - 1, l) // left
		|| find_maze_path(grid, r, c + 1, l) // right
		|| find_maze_path(grid, r, c, l - 1) // down
		|| find_maze_path(grid, r, c, l + 1)){ // up
		return true;
	}
	else {
		grid[r][c][l] = TEMPORARY;  // Dead end.
		solution.pop_back();
		return false;
	}
}

vector<string> Pathfinder::solveMaze() {
	solution.clear();
	find_maze_path(maze_grid, 0, 0, 0);
	/*for (auto s : solution) {
		cout << s << endl;
	}*/
	for (int level = 0; level < LEVEL_SIZE; level++) { // resets original values of maze
		for (int row = 0; row < ROW_SIZE; row++) {
			for (int col = 0; col < COL_SIZE; col++) {
				if (maze_grid[row][col][level] == PATH || maze_grid[row][col][level] == TEMPORARY) {
					maze_grid[row][col][level] = BACKGROUND;
				}
			}
		}
	}
	return solution;
}