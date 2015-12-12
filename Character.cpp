//============================================================================== 
// File name    : Character.cpp
// Author       : Jeffrey Thor
// Date         : 10/12/2015
// Description  : Character Class - Game Of Legends
// Collaborators: David Thor
//==============================================================================

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "Character.h"

using namespace std;

//Default constructor
Character::Character(){
	name = "";
	characterType = "";
	experience = 0;
	level = 0;
	health = 0;
	maxHealth = 0;
	gold = 0;
	alive = false;
	specialAttackName = "";
	srand(time(0));
}

/**
 * Constructor. Sets all of the data members.
 *
 * @param name The name of the character.
 * @param characterType The character's type.
 */
Character::Character(string name, string characterType){
	this->name = name;
	this->characterType = characterType;
}

/**
 * Character superclass default specialAttack method.
 *
 * @return The exit status.
 */
int Character::specialAttack(){
	return 0;
}

/**
 * Constructor. Sets all of the data members.
 *
 * @param name The character's name.
 * @param characterType The character's type.
 */
Warrior::Warrior(string name, string characterType) : Character::Character(name, characterType){
	experience = 0;
	level = 1;
	health = 50;
	maxHealth = 50;
	gold = 500;
	alive = true;
	criticalPoint = 20;
	missPoint = 20;
	damageMultiplier = 1.8;
	specialAttackName = "power-attack";
}

/**
 * The warrior subclasses special attack.
 *
 * @return The damage of the special attack.
 */
int Warrior::specialAttack(){
	int damage = 0;
	if (rand() % 4 == 0){
        cout << "Miss!" << endl;
        cout << "You did 0 points of damage" << endl << endl;
        return damage;
    }
    else if (rand() % criticalPoint == 0){
        cout << "Critical hit!" << endl;
        damage = (((rand() % (level * 2) + (level * level)) * damageMultiplier) * 2) * 2;
        cout << "You did " << damage << " point(s) of damage." << endl << endl;
        return damage;
    }
    else{
    	cout << "Hit!" << endl;
        damage = ((rand() % (level * 2) + (level * level)) * damageMultiplier) * 2;
        cout << "You did " << damage << " point(s) of damage." << endl << endl;
        return damage;
    }
}

/**
 * Constructor. Sets all of the data members.
 *
 * @param name The character's name.
 * @param characterType The character's type.
 */
Wizard::Wizard(string name, string characterType) : Character::Character(name, characterType){
	experience = 0;
	level = 1;
	health = 30;
	maxHealth = 30;
	gold = 500;
	alive = true;
	criticalPoint = 12;
	missPoint = 12;
	damageMultiplier = 1.5;
	specialAttackName = "heal";
}

/**
 * The wizard subclasses special attack.
 *
 * @return The points healed by the attack.
 */
int Wizard::specialAttack(){
	int damage = 0;
	if (rand() % 3 == 0){
		cout << "Heal failed!" << endl << endl;
	}
	else{
		cout << "Healed " << maxHealth/2 << " points!"<< endl;
		health += maxHealth/2;
		if(health > maxHealth)
			health = maxHealth;
	}
	return 0;
}

/**
 * Constructor. Sets all of the data members.
 *
 * @param name The character's name.
 * @param characterType The character's type.
 */
Looter::Looter(string name, string characterType) : Character::Character(name, characterType){
	experience = 0;
	level = 1;
	health = 30;
	maxHealth = 30;
	gold = 1000;
	alive = true;
	criticalPoint = 16;
	missPoint = 16;
	damageMultiplier = 1.5;
	specialAttackName = "quick-hit";
}

/**
 * The looter subclasses special attack.
 *
 * @return The damage of the special attack.
 */
int Looter::specialAttack(){
	int damage = 0;
	int counter = 0;
	damage = ((rand() % (level * 2) + (level * level)) * damageMultiplier) / 2;
	do{
		counter++;
	}while(rand() % 2 == 0);
	damage *= counter;
	if(damage == 0)
		damage = 1;
	if(counter == 0){
		cout << "Miss!" << endl;
		damage = 0;
	}
	else{
		cout << "Hit " << counter << " time(s)!" << endl;
	}
	cout << "You did " << damage << " point(s) of damage." << endl << endl;
	return damage;
}

//Default constructor
Character::~Character(){

}

//Gets character's name.
string Character::getName() const{
	return name;
}
//Gets character's type.
string Character::getCharacterType() const{
	return characterType;
}
//Gets character's experience.
int Character::getExperience() const{
	return experience;
}
//Gets character's level.
int Character::getLevel() const{
	return level;
}
//Gets character's health.
int Character::getHealth() const{
	return health;
}
//Gets character's max health.
int Character::getMaxHealth() const{
	return maxHealth;
}
//Gets character's gold.
int Character::getGold() const{
	return gold;
}
//Gets character's state of life.
bool Character::getAlive() const{
	return alive;
}
//Gets character's special attack name
string Character::getSpecialAttackName() const{
	return specialAttackName;
}

/**
 * Constructor. Sets all of the data members.
 *
 * @param characterType The character's type.
 * @param name The character's name.
 * @param experience The character's experience.
 * @param level The character's level.
 * @param health The character's health.
 * @param maxHealth The character's max health.
 * @param gold The character's gold.
 * @param alive The character's state of life.
 */
void Character::setStats(string characterType, string name, int experience, int level, int health, int maxHealth, int gold, bool alive){
	this->characterType = characterType;
	this->name = name;
	this->experience = experience;
	this->level = level;
	this->health = health;
	this->maxHealth = maxHealth;
	this->gold = gold;
	this->alive = alive;
}

//Sets character's type.
void Character::setCharacterType(string characterType){
	this->characterType = characterType;
}
//Sets character's name.
void Character::setName(string name){
	this->name = name;
}
//Sets character's experience.
void Character::setExperience(int experience){
	this->experience = experience;
}
//Sets character's level.
void Character::setLevel(int level){
	this->level = level;
}
//Sets character's health.
void Character::setHealth(int health){
	this->health = health;
}
//Sets character's max health.
void Character::setMaxHealth(int maxHealth){
	this->maxHealth = maxHealth;
}
//Sets character's gold.
void Character::setGold(int gold){
	this->gold = gold;
}
//Sets character's state of life.
void Character::setAlive(bool alive){
	this->alive = alive;
}

/**
 * Saves the current game state by outputting the character variables into a file.
 *
 * @param save The name of the saves file.
 */
void Character::saveState(string saves){
	ofstream fileOut;
	fileOut.open(saves.c_str());
	fileOut << characterType << endl;
    fileOut << name << endl;
    fileOut << experience << endl;
    fileOut << level << endl;
    fileOut << health << endl;
    fileOut << maxHealth << endl;
    fileOut << gold << endl;
    fileOut << alive;
    if(!items.empty())
    	cout << endl;
	for(int i = 0; i < items.size(); i++){
		fileOut << items[i];
		if(i < items.size()-1){
			fileOut << endl;
		}
	}
	fileOut.close();
}

/**
 * Printst the character stats banner.
 */
void Character::printStats(){
	cout << "================================================================================" << endl;
	cout << "NAME: " << name << " CHARACTER: " << characterType << " LEVEL: " << level << " HEALTH: "
		 << health << "/" << maxHealth << " GOLD: " << gold << endl;
	cout << "================================================================================" << endl << endl;
}

/**
 * Prints the character's possible attacks.
 */
void Character::printAttacks(){
	cout << "\n\"attack\"/\'a\' \"" << specialAttackName <<  "\"/\'s\' " << " \"inventory\"/\'i\' \"flee\"/\'f\'" << endl << endl << endl;
}

/**
 * The character's primary attack.
 *
 * @return The damage of the primary attack.
 */
int Character::primaryAttack(){
    int damage = 0;
    if (rand() % missPoint == 0){
        cout << "Miss!" << endl;
        cout << "You did 0 points of damage." << endl << endl;
        return damage;
    }
    else if (rand() % criticalPoint == 0){
        cout << "Critical hit!" << endl;
        damage = ((rand() % (level * 2) + (level * level)) * damageMultiplier) * 2;
        cout << "You did " << damage << " point(s) of damage." << endl << endl;
        return damage;
    }
    else{
    	cout << "Hit!" << endl;
        damage = (rand() % (level * 2) + (level * level)) * damageMultiplier;
        cout << "You did " << damage << " point(s) of damage." << endl << endl;
        return damage;
    }
}

/**
 * Adds an item to the character's inventory.
 *
 * @param item The item to be added.
 */
void Character::addItem(string item){
	items.push_back(item);
}

/**
 * Uses an item to the character's inventory.
 *
 * @param item The item to be added.
 * @param position The location of the item in the character's inventory
 */
void Character::useItem(string item, int position){
	int healthAdded;
	if(item == "potion"){
		healthAdded = 40;
	}
	else if(item == "strong-potion"){
		healthAdded = 100;
	}
	else if(item == "stronger-potion"){
		healthAdded = 500;
	}
	else if(item == "strongest-potion"){
		healthAdded = maxHealth/2;
	}
	else if(item == "revive"){
		alive = true;
		healthAdded = maxHealth/2;
		cout << "You've been revived!" << endl;
	}
	else{
		cout << "Input Error!" << endl;
	}
	health += healthAdded;
	items.erase(items.begin()+position);
	if(health > maxHealth)
		health = maxHealth;
	cout << "You gained " << healthAdded << " health!" << endl << endl;
}

/**
 * Prints the character's inventory and prompts player to use an item.
 */
void Character::inventory(){
	string choice;
	string check;
	cout << "\t\t\t\t   INVENTORY" << endl;
	cout << "================================================================================" << endl;
	for(vector<string>::const_iterator i = items.begin(); i < items.end(); i++)
		cout << "\"" << *i << "\" ";
	cout << endl;
	cout << "================================================================================" << endl << endl;
	cout << "What would you like to use? Or you may \"exit\"" << endl << endl;
	cout << name << ": ";
	cin.clear();
	getline(cin, choice);
	cout << endl;
	for(int i = 0; i < items.size(); i++){
		if(items[i] == choice){
			if(choice == "revive" && alive == true){
				cout << "I'm sorry, that isn't an option. You may not use revives at this time." << endl << endl;
			}
			else{
				cout << "So you would like to use 1 " << choice << "? \"yes\" or \"no\"" << endl << endl;
				cout << name << ": ";
				getline(cin, check);
				cout << endl;
				if(check == "yes"){
					useItem(choice, i);
					break;
				}
				else if(choice == "no"){
					inventory();
				}
				else{
					cout << "I'm sorry, that isn't an option." << endl << endl;
					inventory();
				}
			}
		}
		else if(choice == "exit"){

		}
		else if(items[i] != choice && i == items.size()-1){
			cout << "I'm sorry, that's not available." << endl << endl;
		}
	}
}