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
#include <vector>
#include <fstream>
#include "Character.h"

using namespace std;

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

Character::Character(string name, string characterType){
	this->name = name;
	this->characterType = characterType;
}

Warrior::Warrior(string name, string characterType) : Character::Character(name, characterType){
	experience = 0;
	level = 1;
	health = 50;
	maxHealth = 50;
	gold = 500;
	alive = true;
	criticalPoint = 20;
	damageMultiplier = 1.8;
	specialAttackName = "power-attack";
}

Wizard::Wizard(string name, string characterType) : Character::Character(name, characterType){
	experience = 0;
	level = 1;
	health = 30;
	maxHealth = 30;
	gold = 500;
	alive = true;
	criticalPoint = 12;
	damageMultiplier = 1.5;
	specialAttackName = "heal";
}

Looter::Looter(string name, string characterType) : Character::Character(name, characterType){
	experience = 0;
	level = 1;
	health = 30;
	maxHealth = 30;
	gold = 1000;
	alive = true;
	criticalPoint = 16;
	damageMultiplier = 1.5;
	specialAttackName = "quick-hit";
}

Character::~Character(){

}

string Character::getName() const{
	return name;
}

string Character::getCharacterType() const{
	return characterType;
}

int Character::getExperience() const{
	return experience;
}

int Character::getLevel() const{
	return level;
}

int Character::getHealth() const{
	return health;
}

int Character::getMaxHealth() const{
	return maxHealth;
}

int Character::getGold() const{
	return gold;
}

bool Character::getAlive() const{
	return alive;
}

string Character::getSpecialAttackName() const{
	return specialAttackName;
}

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

void Character::setCharacterType(string characterType){
	this->characterType = characterType;
}

void Character::setName(string name){
	this->name = name;
}

void Character::setExperience(int experience){
	this->experience = experience;
}

void Character::setLevel(int level){
	this->level = level;
}

void Character::setHealth(int health){
	this->health = health;
}

void Character::setMaxHealth(int maxHealth){
	this->maxHealth = maxHealth;
}

void Character::setGold(int gold){
	this->gold = gold;
}

void Character::setAlive(bool alive){
	this->alive = alive;
}

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

void Character::printStats(){
	cout << "================================================================================" << endl;
	cout << "NAME: " << name << " CHARACTER: " << characterType << " LEVEL: " << level << " HEALTH: "
		 << health << "/" << maxHealth << " GOLD: " << gold << endl;
	cout << "================================================================================" << endl << endl;
}

void Character::printAttacks(){
	cout << "\n\"attack\" \"" << specialAttackName <<  "\" \"inventory\" \"flee\"" << endl << endl << endl;
}

int Character::primaryAttack(){
    int damage = 0;
    if (rand() % criticalPoint == 0){
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

int Character::specialAttack(){
	int damage = 0;
	int counter = 0;
	if(characterType == "warrior"){
		if (rand() % 3 == 0){
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

	else if(characterType == "wizard"){
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
	else if(characterType == "looter"){
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
	else{
		cout << "Conditional Error!" << endl;
		return 0;
	}
}

void Character::addItem(string item){
	items.push_back(item);
}

void Character::useItem(string item, int position){
	int healthAdded;
	if(item == "potion"){
		healthAdded = 40;
	}
	else if(item == "strong-potion"){
		healthAdded = 100;
	}
	else if(item == "power-potion"){
		healthAdded = 500;
	}
	else if(item == "max-potion"){
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
	//items.erase(position);
	if(health > maxHealth)
		health = maxHealth;
	cout << "You gained " << healthAdded << " health!" << endl << endl;
}

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
				cin.ignore(10000,  '\n');
				getline(cin, check);
				cout << endl;
				if(check == "yes"){
					useItem(choice, i);
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

void Character::setShop(){
	string tempItems [5] = {"potion", "strong-potion", "power-potion", "max-potion", "revive"};
	shopItems.insert(shopItems.end(), tempItems, tempItems+5);
	int tempPrices [5] = {200, 400, 800, 2000, 5000};
	shopPrices.insert(shopPrices.end(), tempPrices, tempPrices+5);
}

void Character::shop(){
	string choice;
	bool check;
	int count;
	int price;
	do{
		printStats();
		cout << "\t\t\t      WELCOME TO THE SHOP" << endl;
		cout << "================================================================================" << endl;
		for(int i = 0; i < shopItems.size(); i++)
			cout << "\"" << shopItems[i] << "\" x" << shopPrices[i] << " gold      ";
		cout << endl;
		cout << "================================================================================" << endl << endl;

		cout << "What would you like to purchase? Or you may \"leave\"." << endl << endl;
		cout << name << ": ";
		cin.clear();
		getline(cin, choice);
		cout << endl;
		for(int i = 0; i != shopItems.size(); i++){
			if(shopItems[i] == choice){
				check = true;
				price = shopPrices[i];
			}
		}
		if(choice == "leave"){
			break;
		}
		else if(check){
			check = false;
			cout << "How many would you like? \"1\", \"2\", \"3\",...\"99\"" << endl << endl;
			cout << name << ": ";
			cin >> count;
			cout << endl;
			for(int i = 1; i <= 99; i++){
				if(count == i)
					check = true;
			}
			if(check){
				if(price * count > gold)
					cout << "You don't have enough gold!" << endl << endl;
				else{
					for(int i = 0; i < count; i++){
						addItem(choice);
					}
					gold -= count * price;
					cout << "Here you go, " << count << " " << choice << "(s)." << endl << endl;
					cout << "Press enter to return to the shop" << endl;
					cin.ignore(10000, '\n');
					cin.get();
				}
			}
			else
				cout << "I'm sorry, that's not an option." << endl << endl;
		}
		else
			cout << "I'm sorry, that isn't an option." << endl << endl;
	}while(choice != "leave");
}