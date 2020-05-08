#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <list>
using namespace std;


// PART 7 of Lab 3
int main(int argc, char *argv[]) {
	vector<string> tokens;
	string next_line;  // Each data line
	ifstream in(argv[1]);
	ofstream output_file;
	map<list<string>, vector<string>> wordmap;
	list<string> state;
	int M = 100;
	srand(time(NULL)); // this line initializes the random number generated
				   // so you dont get the same thing every time

	while (getline(in, next_line)) {
		istringstream iss(next_line);
		string token;
		while (iss >> token) {
			string nopunct = "";
			for (auto &c : token) { // Remove Punctuation      
				if (isalpha(c)) {
					nopunct += c;
				}
			}
			tokens.push_back(nopunct);
		}
	}

	for (int i = 0; i < M; i++) {
		state.push_back("");
	}

	for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++) {
		wordmap[state].push_back(*it);
		state.push_back(*it);
		state.pop_front();
	}

	state.clear();
	output_file.open("Edgar_Allan_Poe.txt");
	for (int i = 0; i < M; i++) {
		state.push_back("");
	}
	for (int i = 0; i < 100; i++) {
		int ind = rand() % wordmap[state].size();
		cout << wordmap[state][ind] << " ";
		output_file << wordmap[state][ind] << " ";
		state.push_back(wordmap[state][ind]);
		state.pop_front();
	}
	cout << endl;
	output_file << endl;
	output_file.close();
}
