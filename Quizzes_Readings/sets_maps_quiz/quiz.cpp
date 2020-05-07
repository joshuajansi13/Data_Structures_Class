#include <set>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>
using namespace std;
int main(int argc, char *argv[])
{
	// Sets
	set <string> strset;
	strset.insert("bug");
	strset.insert("horse");
	strset.insert("horse");
	set<string>::iterator findit;
	findit = strset.find("horse");
	cout << "Found horse "<< *findit<<endl;
	for (set<string>::iterator it=strset.begin(); it!=strset.end(); ++it) {
		cout << ' ' << *it;
	        cout << endl;
	}
}
