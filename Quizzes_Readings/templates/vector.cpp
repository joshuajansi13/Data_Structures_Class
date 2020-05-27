#include <iostream>
#include <vector>
#include "MV.h"
#include "MyVector.h"
#include <string>
using std::cout;
using std::endl;
using std::string;
int main()
{
    vector<int> intvec;
    intvec.push_back(17);
    cout << "Position 0 "<<intvec[0]<<endl;
    cout << "Position 0 "<<intvec.at(0)<<endl;
    
    vector<string> stringvec;
    stringvec.push_back("Hello");
    cout << "Position 0 "<<stringvec[0]<<endl;
    cout << "Position 0 "<<stringvec.at(0)<<endl;
    
    MV<int> intcontainer;
    cout << "Inserting"<<endl;
    intcontainer.put(5);
    cout << "Getting "<<intcontainer.get()<<endl;
    
    MV<string> stringcontainer;
    cout << "Inserting"<<endl;
    stringcontainer.put("Hello");
    cout << "Getting "<<stringcontainer.get()<<endl;
    
    MyVector<int> myvecint;
    myvecint.push_back(5);
    myvecint.insertAt(0, 6);
    cout << "Size "<<myvecint.size()<<endl;
    myvecint.remove(0);
    cout << "Zero " << myvecint.at(0)<<endl;
    
}

