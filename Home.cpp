//============================================================================== 
// File name    : Character.cpp
// Author       : Jeffrey Thor
// Date         : 10/24/2015
// Description  : Home Class - Game of Legends
// Collaborators: n/a
//==============================================================================

#include <iostream>
#include <thread>
#include <chrono>
#include "Home.h"
#include "Character.h"

using namespace std;

//Default constructor.
Home::Home(){

}

/**
 * Introduces the home to the player.
 *
 * @param character The player's character.
 */
void Home::intro(Character *character){
	string choice;
	cout << "Hi " << character->getName() << ", Welcome home!" << endl << endl;
	if(character->getAlive()){
		do{
			cout << "Would you like to take a quick rest before heading back out? \"yes\" or \"no\"" << endl << endl;
			cout << character->getName() << ": ";
			getline(cin, choice);
			cout << endl;
			if(choice == "yes")
				rest(character);
			else if(choice == "no")
				cout << "Alright, well thanks for stopping by!" << endl << endl;
			else
				cout << "I'm sorry, that isn't an option." << endl << endl;
		}while(choice != "yes" && choice != "no");
	}
	else{
		cout << "Looks like you've been having some trouble, you should take a rest." << endl << endl;
		rest(character);
	}
}

/**
 * Rests and heals the player's character.
 *
 * @param character The player's character.
 */
void Home::rest(Character *character){
	int restTime;
	if(character->getAlive())
		restTime = 3;
	else
		restTime = 8;
	cout << "Resting, please wait..." << endl << endl;
	this_thread::sleep_for (std::chrono::seconds(restTime));
	cout << "That's better, you've been returned to full health!" << endl;
	character->setAlive(true);
	character->setHealth(character->getMaxHealth());
	cout << "Press enter to return to the village." << endl;
	cin.get();
}