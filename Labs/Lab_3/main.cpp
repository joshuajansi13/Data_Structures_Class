#include <set>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>
#include <string>
#include <list>
using namespace std;


int main(int argc, char *argv[]) {
	vector<string> tokens;
	set <string> unique;
	string next_line;  // Each data line
	ifstream in(argv[1]);
	ofstream myfile;
	string filename = string(argv[1]);

	// PARTS 1 & 2
	// put each word into a vector and set
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
			unique.insert(nopunct);
		}
	}
	cout << "Number of words " << tokens.size() << endl;
	cout << "Number of unique words " << unique.size() << endl;
	
	// writes each word from set to 1Nephi.txt_set.txt
	myfile.open(filename + "_set.txt");
	for (set<string>::iterator it = unique.begin(); it != unique.end(); it++) {
		myfile << *it << endl;
	}
	myfile.close();

	// writes each word from vector to 1Nephi.txt_vector.txt
	myfile.open(filename + "_vector.txt");
	for (int i = 0; i < tokens.size(); i++) {
		myfile << tokens[i] << endl;
	}
	myfile.close();

	//// PART 3
	//// creates the map
	//map<string, string> wordmap;
	//string last = "";
	//for (int i = 0; i < tokens.size(); i++) {
	//	wordmap[last] = tokens[i];
	//	last = tokens[i];
	//}

	//// outputs the key, value pair to 1Nephi.txt_map.txt
	//myfile.open(filename + "_map.txt");
	//for (map<string, string>::iterator it = wordmap.begin(); it != wordmap.end(); it++) {
	//	//cout << it->first << ", " << it->second << endl;
	//	myfile << it->first << ", " << it->second << endl;
	//}
	//myfile.close();

	//// PART 4
	//// generates 100 words of text from the map we created
	//string state = "";
	//for (int i = 0; i < 100; i++) {
	//	cout << wordmap[state] << " ";
	//	state = wordmap[state];
	//}
	//cout << endl;

	//// PART 5
	//// rewrites wordmap as <string, vector<string>> 
	//// this will keep track of all of the words seen after a specific word 
	//map<string, vector<string>> wordmap;
	//string state = "";
	//for (int i = 0; i < tokens.size(); i++) {
	//	wordmap[state].push_back(tokens[i]);
	//	state = tokens[i];
	//}

	//// check to see if you get the right output
	//for (map<string, vector<string>>::iterator it = wordmap.begin(); it != wordmap.end(); it++) {
	//	if (it->first == "Nephi") {
	//		for (vector<string>::iterator iter = wordmap["Nephi"].begin(); 
	//			iter != wordmap["Nephi"].end(); iter++) {
	//			cout << *iter << ", ";
	//		}
	//		break;
	//	}
	//}
	//cout << endl;

	//// generates a better sermon by randomly picking a tring from the vector 
	//// of strings associated with the "key" (which is the last word spoken)
	//// 100 word sermon
	srand(time(NULL)); // this line initializes the random number generated
				   // so you dont get the same thing every time
	//state = "";
	//for (int i = 0; i < 100; i++) {
	//	int ind = rand() % wordmap[state].size();
	//	cout << wordmap[state][ind] << " ";
	//	state = wordmap[state][ind];
	//}
	//cout << endl;

	// PART 6
	map<list<string>, vector<string>> wordmap;
	list<string> state;
	int M = 3;
	for (int i = 0; i < M; i++) {
		state.push_back("");
	}

	for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++) {
		wordmap[state].push_back(*it);
		state.push_back(*it);
		state.pop_front();
	}

	state.clear();
	for (int i = 0; i < M; i++) {
		state.push_back("");
	}
	for (int i = 0; i < 100; i++) {
		int ind = rand() % wordmap[state].size();
		cout << wordmap[state][ind] << " ";
		state.push_back(wordmap[state][ind]);
		state.pop_front();
	}
	cout << endl;

	// PART 7

}
