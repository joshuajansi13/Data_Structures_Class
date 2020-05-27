#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

int main()
{
	stringstream ss("Speedy R P");
	string name, type;
	int speed;
	ss.exceptions(ios_base::failbit);

	try {
		ss >> name >> type >> speed;
	} 
	catch(ios_base::failure& ex) {
		cout << "Error "<<ex.what()<<endl;
  	}
}
