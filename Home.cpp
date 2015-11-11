//============================================================================== 
// File name    : Character.cpp
// Author       : Jeffrey Thor
// Date         : 10/24/2015
// Description  : Home Class - Game of Legends
// Collaborators: n/a
//==============================================================================

#include <iostream>
//#include <unistd.h>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>
#include "Home.h"
#include "Character.h"

using namespace std;

Home::Home(){

}

void Home::intro(Character *character){
	string choice;
	cout << "Hi " << character->getName() << ", Welcome home!" << endl << endl;
	do{
		cout << "Would you like to take a quick rest before heading back out? \"yes\" or \"no\"" << endl << endl;
		cout << character->getName() << ": ";
		cin >> choice;
		cout << endl;
		if(choice == "yes")
			character->setHealth(rest(character->getMaxHealth()));
		else if(choice == "no")
			cout << "Alright, well thanks for stopping by!" << endl << endl;
		else
			cout << "I'm sorry, that isn't an option" << endl << endl;
	}while(choice != "yes" && choice != "no");
}

int Home::rest(int maxHealth){
	cout << "Resting..." << endl << endl;
	this_thread::sleep_for (std::chrono::seconds(3));
	cout << "That's better, you've been returned to full health!" << endl << endl;
	return maxHealth;
}