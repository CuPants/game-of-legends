//============================================================================== 
// File name    : Character.cpp
// Author       : Jeffrey Thor
// Date         : 10/23/2015
// Description  : Character Class - Game of Legends
// Collaborators: n/a
//==============================================================================

#include <iostream>
#include <vector>
#include "Village.h"

using namespace std;

Village::Village(){

}

Village::~Village(){

}

void Village::setLocations(){
	string tempLocations [5] = {"home", "path", "inventory", "shop", "river"};
	locations.insert(locations.end(), tempLocations, tempLocations+5);
}

void Village::updateLocations(int level){
	if(level >= 10 && level < 15)
		locations.push_back("forest");
	else if(level >= 15 && level < 20)
		locations.push_back("cliff");
	else if(level >= 20)
		locations.push_back("mountain");
}

void Village::printLocations(){
	cout << "================================================================================" << endl;
	for(vector<string>::const_iterator i = locations.begin(); i != locations.end(); i++)
		cout << "\"" << *i << "\" ";
	cout << endl;
	cout << "================================================================================" << endl << endl;
}