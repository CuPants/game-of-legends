//============================================================================== 
// File name    : main.cpp
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
	level = 0;
	health = 0;
	gold = 0;
	srand(time(0));
}

Character::Character(string newName){
	name = newName;
}

Warrior::Warrior(string name) : Character::Character(name){
	level = 1;
	health = 400;
	gold = 500;
	criticalPoint = 20;
	items.push_back("potion");
}

Wizard::Wizard(string name) : Character::Character(name){
	level = 1;
	health = 200;
	gold = 500;
	criticalPoint = 12;
	items.push_back("potion");
}

Looter::Looter(string name) : Character::Character(name){
	level = 1;
	health = 200;
	gold = 1000;
	criticalPoint = 16;
	items.push_back("potion");
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

void Character::addPotion(){
	items.push_back("potion");
}

void Character::inventory(){
	cout << "================================================================================" << endl;
	for(int i = 0; i <= items.size(); i++)
		cout << "\"" << items[i] << "\" ";
	cout << endl;
	cout << "================================================================================" << endl;
}