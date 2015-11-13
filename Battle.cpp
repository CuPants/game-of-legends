//============================================================================== 
// File name    : Battle.cpp
// Author       : Jeffrey Thor
// Date         : 11/12/2015
// Description  : Battle Class - Game of Legends
// Collaborators: n/a
//==============================================================================

#include <iostream>
#include "Battle.h"
#include "Character.h"
#include "Enemy.h"

using namespace std;

Battle::Battle(){

}

void Battle::intro(Character *character, Enemy *enemy){
	cin.ignore(10000, '\n');
	cout << "Welcome to your first battle!" << endl << endl;
	cout << "The battle screen is where you will fight all of your enemies. You know you are\nin a battle when you are displayed with attack options and the stats of your\nenemy." << endl << endl;
	cout << "Press enter to begin, good luck!" << endl;
	cin.get();
	cout << endl;
	screen(character, enemy);
}

void Battle::screen(Character *character, Enemy *enemy){
	string choice;
	locale loc;
	int count = 0;
	do{

	enemy->printStats();

	for (string::size_type i=0; i < (80 - enemy->getEnemyType().length())/2; ++i)
    	cout << " ";
	for (string::size_type i=0; i < enemy->getEnemyType().length(); ++i)
    	cout << toupper(enemy->getEnemyType()[i],loc);
    cout << endl << endl;
	cout << "                                     - VS -" << endl << endl;

	for (string::size_type i=0; i < (80 - character->getName().length())/2; ++i)
    	cout << " ";
	for (string::size_type i=0; i < character->getName().length(); ++i)
    	cout << toupper(character->getName()[i],loc);
    cout << endl;

	character->printStats();
	if(count != 0)
		character->setHealth(character->getHealth() - enemy->primaryAttack());
	character->printAttacks();
	cout << character->getName() << ": ";
	getline(cin, choice);
	attackChoice(character, enemy, choice);
	count++;
	}while(enemy->getAlive() && character->getAlive());
}

void Battle::attackChoice(Character *character, Enemy *enemy, string choice){
	if(choice == "attack"){
		enemy->setHealth(enemy->getHealth() - character->primaryAttack());
	}
	else if(choice == character->getSpecialAttackName()){

	}
	else if(choice == "inventory"){
		character->inventory();
	}
	else if(choice == "flee"){
		cout << "You've escaped the battle. Press enter to return to the village." << endl;
		cin.get();
		
	}

	if(enemy->getHealth() <= 0){
		enemy->setAlive(false);
		cout << "You won the battle!" << endl << endl;
		cout << "Press enter to continue." << endl;
		cin.get();
	}
	else if(character->getHealth() <= 0){
		character->setAlive(false);
		cout << "You lost the battle!" << endl << endl;
		cout << "You lost " << character->getGold() << " gold." << endl << endl;
		cout << "Press enter to return home." << endl;
		cin.get();
	}
}