#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int add2(int a) {
	return a+2;
}

int main(int argc, char *argv[])
{
	cout << "Reading file" << endl;
	if (argc != 2) {
		cout << "Please provide a filename" << endl;
	}
	else {
		ifstream fileHandle(argv[1]);
		if (!fileHandle.is_open()) {
			cout << "could not open file" << endl;
		}
		else {
			vector<string> lines;
			string line;
			while (fileHandle >> line) {
				lines.push_back(line);
			}
			cout << add2(lines.size()) << " : " << lines[0] << endl;
		}
	}
}
