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
#include "Character.h"

using namespace std;

Character::Character(){
	name = "";
	characterType = "";
	level = 0;
	health = 0;
	gold = 0;
	alive = false;
	srand(time(0));
}

Character::Character(string newName, string newCharacterType){
	name = newName;
	characterType = newCharacterType;
}

Warrior::Warrior(string name, string characterType) : Character::Character(name, characterType){
	characterType = "warrior";
	level = 1;
	health = 400;
	gold = 500;
	alive = true;
	criticalPoint = 20;
}

Wizard::Wizard(string name, string characterType) : Character::Character(name, characterType){
	characterType = "wizard";
	level = 1;
	health = 200;
	gold = 500;
	alive = true;
	criticalPoint = 12;
}

Looter::Looter(string name, string characterType) : Character::Character(name, characterType){
	characterType = "looter";
	level = 1;
	health = 200;
	gold = 1000;
	alive = true;
	criticalPoint = 16;
}

Character::~Character(){

}

string Character::getName() const{
	return name;
}

int Character::getLevel() const{
	return level;
}

int Character::getHealth() const{
	return health;
}

int Character::getGold() const{
	return gold;
}

bool Character::getAlive() const{
	return alive;
}

void Character::setName(string newName){
	name = newName;
}

void Character::setLevel(int newLevel){
	level = newLevel;
}

void Character::setHealth(int newHealth){
	health = newHealth;
}

void Character::setGold(int newGold){
	gold = newGold;
}

void Character::setAlive(bool newAlive){
	alive = newAlive;
}

void Character::printStats(){
	cout << "================================================================================" << endl;
	cout << "NAME: " << name << " CHARACTER: " << characterType << " LEVEL: " << level << " HEALTH: " << health << " GOLD: " << gold << " ALIVE: " << boolalpha << alive << endl;
	cout << "================================================================================" << endl << endl;
}

int Character::primaryAttack(){
    int damage = 0;
    if (rand() % criticalPoint == 0){
        cout << "Miss!" << endl;
        cout << "You did 0 points of damage" << endl << endl;
        return 0;
    }
    else if (rand() % criticalPoint == 0){
        cout << "Critical hit!" << endl;
        damage = (rand() % (level * 2) + (level * level)) * 2;
        cout << "You did " << damage << " point(s) of damage" << endl << endl;
        return damage;
    }
    else{
        damage = rand() % (level * 2) + (level * level);
        cout << "You did " << damage << " point(s) of damage" << endl << endl;
        return damage;
    }
}

void Character::addItem(string item){
	items.push_back(item);
}

void Character::inventory(){
	cout << "                                   INVENTORY                                    " << endl;
	cout << "================================================================================" << endl;
	for(vector<string>::const_iterator i = items.begin(); i != items.end(); i++)
		cout << "\"" << *i << "\" ";
	cout << endl;
	cout << "================================================================================" << endl << endl;
}

void Character::setShop(){
	string tempItems [5] = {"potion", "strong potion", "power potion", "max potion", "revive"};
	shopItems.insert(shopItems.end(), tempItems, tempItems+5);
	int tempPrices [5] = {200, 400, 800, 2000, 5000};
	shopPrices.insert(shopPrices.end(), tempPrices, tempPrices+5);
}

void Character::shop(){
	string choice;
	bool check;
	int count;
	int price;
	cout << "                              WELCOME TO THE SHOP                               " << endl;
	do{
		cout << "================================================================================" << endl;
		for(int i = 0; i != shopItems.size(); i++)
			cout << "\"" << shopItems[i] << "\" x" << shopPrices[i] << " gold\t";
		cout << endl;
		cout << "================================================================================" << endl << endl;

		cout << "What would you like to purchase? Or you may \"leave\"." << endl << endl;
		cout << name << ": ";
		cin >> choice;
		for(int i = 0; i != shopItems.size(); i++){
			if(shopItems[i] == choice){
				check = true;
				price = shopPrices[i];
			}
		}
		if(choice == "leave"){

		}
		else if(check){
			check = false;
			cout << "How many would you like? \"1\", \"2\", \"3\",...\"99\"" << endl;
			cout << name << ": ";
			cin >> count;
			for(int i = 1; i <= 99; i++){
				if(count == i)
					check = true;
			}
			if(check){
				if(price * count > gold)
					cout << "You don't have enough gold!" << endl << endl;
				else{
					Character::addItem(choice);
					gold -= count * price;
					cout << "Here you go, " << count << " " << choice << "[s]. What else would you like?" << endl << endl;
				}
			}
			else
				cout << "I'm sorry, that's not an option." << endl << endl;
		}
		else
			cout << "I'm sorry, that isn't an option." << endl << endl;
	}while(choice != "leave");
}