//============================================================================== 
// File name    : Battle.cpp
// Author       : Jeffrey Thor
// Date         : 11/12/2015
// Description  : Battle Class - Game of Legends
// Collaborators: n/a
//==============================================================================

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include "Battle.h"
#include "Character.h"
#include "Enemy.h"
#include "Home.h"

using namespace std;

Battle::Battle(){

}

void Battle::intro(Character *character, Enemy *enemy, bool &won){
	cin.ignore(10000, '\n');
	cout << "Welcome to your first battle!" << endl << endl;
	cout << "The battle screen is where you will fight all of your enemies. You know you are\n"
		 << "in a battle when you are displayed with attack options and the stats of your\n"
		 << "enemy." << endl << endl;
	cout << "Press enter to begin, good luck!" << endl;
	screen(character, enemy, won);
}

void Battle::screen(Character *character, Enemy *enemy, bool &won){
	string choice;
	locale loc;
	bool firstPass = true, validChoice = true, over = false;
	string temp;
	int damage;
	cin.ignore(10000, '\n');
	do{
		enemy->printStats();

		for (string::size_type i=0; i < (80 - enemy->getEnemyType().length())/2; ++i)
   			cout << " ";
		for (string::size_type i=0; i < enemy->getEnemyType().length(); ++i)
   			cout << toupper(enemy->getEnemyType()[i],loc);
   		cout << endl << endl;
		cout << "\t\t\t\t     - VS -" << endl << endl;

		for (string::size_type i=0; i < (80 - character->getName().length())/2; ++i)
    		cout << " ";
		for (string::size_type i=0; i < character->getName().length(); ++i)
    		cout << toupper(character->getName()[i],loc);
    	cout << endl;
    	if(!firstPass){
    		damage = enemy->primaryAttack(temp);
			character->setHealth(character->getHealth() - damage);
			if(character->getHealth() <= 0)
				character->setHealth(0);
		}
		character->printStats();
		if(!firstPass)
			enemy->printAttack(temp, damage);
		do{
			if(character->getHealth() > 0){
				character->printAttacks();
				cout << character->getName() << ": ";
				getline(cin, choice);
				cout << endl;
			}
			attackChoice(character, enemy, choice, validChoice, over, won);
			if(!validChoice)
				cout << "I'm sorry, that isn't an option." << endl << endl;
		}while(!validChoice);
	firstPass = false;
	}while(!over);
}

void Battle::attackChoice(Character *character, Enemy *enemy, string choice, bool &validChoice, bool &over, bool &won){
	Home home;
	locale loc;
	int xp;
	int gold;
	bool revived = false;
	if(character->getHealth() > 0){
		if(choice == "attack"){
			validChoice = true;
			enemy->setHealth(enemy->getHealth() - character->primaryAttack());
		}
		else if(choice == character->getSpecialAttackName()){
			validChoice = true;
			enemy->setHealth(enemy->getHealth() - character->specialAttack());
		}
		else if(choice == "inventory"){
			validChoice = true;
			character->inventory();
		}
		else if(choice == "flee"){
			validChoice = true;
			over = true;
			won = false;
			cout << "You've escaped the battle. Press enter to return to the village." << endl;
			cin.get();
		}
		else
			validChoice = false;
	}

	if(enemy->getHealth() <= 0){
		over = true;
		won = true;
		enemy->setHealth(0);
		enemy->setAlive(false);
		enemy->printStats();

		for (string::size_type i=0; i < (80 - enemy->getEnemyType().length())/2; ++i)
    		cout << " ";
		for (string::size_type i=0; i < enemy->getEnemyType().length(); ++i)
    		cout << toupper(enemy->getEnemyType()[i],loc);
    	cout << endl << endl;
		cout << "\t\t\t\t     - VS -" << endl << endl;
		for (string::size_type i=0; i < (80 - character->getName().length())/2; ++i)
    		cout << " ";
		for (string::size_type i=0; i < character->getName().length(); ++i)
    		cout << toupper(character->getName()[i],loc);
    	cout << endl;
    	character->printStats();
    	cout << endl << endl;
    	cout << enemy->getEnemyType() << " died." << endl;
		cout << "You won the battle!" << endl << endl;
		xp = sqrt(enemy->getLevel()*1000);
		if(character->getCharacterType() == "looter")
			gold = enemy->getLevel()*70;
		else
			gold = enemy->getLevel()*40;
		character->setExperience(character->getExperience() + xp);
		character->setGold(character->getGold() + gold);
		cout << "You gained " << xp << " experience." << endl;
		cout << "You received " << gold << " gold." << endl;
		if(character->getExperience() >= character->getLevel()*20){
			cout << "LEVEL UP!" << endl << endl;
			character->setLevel(character->getLevel()+1);
			character->setMaxHealth(character->getMaxHealth() + character->getLevel()*20);
			character->setHealth(character->getMaxHealth());
			character->setExperience(0);
		}
		cout << "Press enter to continue." << endl;
		cin.get();
	}
	else if(character->getHealth() <= 0){
		over = true;
		won = false;
		character->setHealth(0);
		character->setAlive(false);
		cout << "You lost the battle!" << endl << endl;
		do{
			for(int i = 0; i < character->items.size(); i++){
				if(character->items[i] == "revive"){
					cout << "Would you like to use a revive? \"yes\" or \"no\"" << endl << endl;
					cin >> choice;
					cout << endl;
					break;
				}
			}
			if(choice == "yes"){
				for(int i = 0; i < character->items.size(); i++){
					if(character->items[i] == "revive"){
						character->useItem("revive", i);
						revived = true;
						over = false;
						cin.clear();
						break;
					}
					else if(character->items[i] != "revive" && i == character->items.size()){
						cout << "I'm sorry, you don't have any available." << endl << endl;
					}
				}
			}
			else if(choice == "no"){

			}
			else{
				cout << "I'm sorry, that isn't an option." << endl << endl;
			}
		}while(choice != "yes" && choice != "no");
		if(!revived){
			cout << "You lost " << character->getGold()/2 << " gold." << endl << endl;
			character->setGold(character->getGold()/2);
			cout << "Press enter to return home." << endl;
			cin.get();
			home.intro(character);
		}
	}
}