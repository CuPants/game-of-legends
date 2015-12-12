//============================================================================== 
// File name    : Village.cpp
// Author       : Jeffrey Thor
// Date         : 10/23/2015
// Description  : Village Class - Game of Legends
// Collaborators: n/a
//==============================================================================

#include <iostream>
#include <vector>
#include "Village.h"
#include "Character.h"

using namespace std;

//Default constructor.
Village::Village(){

}

/**
 * Introduces the player to the village.\
 */
void Village::intro(){
	cout << "Welcome to The Village! This will be your home from now on. Here you have access\n"
		 << "to your home, the shop, and all of the primary locations. You can travel back\n"
		 << "here at any time to return to safety. Follow the path to continue your journey\n"
		 <<	"and discover what lies ahead. But be warned, although the village is a safe \n"
		 <<	"place, the same can't be said for what lies beyond..." << endl << endl;

	cout << "Press enter to continue" << endl;
	cin.get();
}

/**
 * Sets the villages locations.
 */
void Village::setLocations(){
	locations.clear();
	string tempLocations [7] = {"home", "path", "inventory", "shop", "river", "save", "quit"};
	locations.insert(locations.end(), tempLocations, tempLocations+7);
}

/**
 * Updates the possible village locations based on the character's level.
 *
 * @param level The level of the character.
 */
void Village::updateLocations(int level){
	if(level >= 10 && locations.size() < 8)
		//locations.push_back("forest");
		locations.insert(locations.begin()+5, "forest");
	if(level >= 15 && locations.size() < 9)
		//locations.push_back("cliff");
		locations.insert(locations.begin()+6, "cliff");
	if(level >= 20 && locations.size() < 10)
		//locations.push_back("mountain");
		locations.insert(locations.begin()+7, "mountain");
}

/**
 * Prints the possible village locations.
 */
void Village::printLocations(){
	cout << "\t\t\t\t  - VILLAGE -" << endl;
	cout << "================================================================================" << endl;
	for(vector<string>::const_iterator i = locations.begin(); i != locations.end(); i++)
		cout << "\"" << *i << "\" ";
	cout << endl;
	cout << "================================================================================" << endl << endl;
}

/**
 * Prompts the user to select a location.
 *
 * @param name The character's name.
 * @return The location the player chose.
 */
string Village::selection(string name){
	string choice;
	bool check;
	do{
		cout << "Where would you like to go?" << endl << endl;
		cout << name << ": ";
		getline(cin, choice);
		cout << endl;
		for(int i = 0; i != locations.size(); i++){
			if(locations[i] == choice){
				check = true;
			}
		}
		if(!check)
			cout << "I'm sorry, that isn't an option." << endl << endl;
	}while(!check);
	return choice;
}