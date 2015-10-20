//============================================================================== 
// File name    : Character.h
// Author       : Jeffrey Thor
// Date         : 10/12/2015
// Description  : Character Class - Game of Legends
// Collaborators: David Thor
//==============================================================================

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
using namespace std;

class Character{
protected:
	string name;
	int level;
	int health;
	int gold;
	int criticalPoint;
	std::vector<string> items;
public:
	//default constructor
	Character();
	//overload constructor 
	Character(string);
	//destructor
	~Character();
	//accessor functions
	string getName() const;
	int getLevel() const;
	int getHealth() const;
	int getGold() const;
	//mutator functions
	void setName(string);
	void setLevel(int);
	void setHealth(int);
	void setGold(int);
	//other functions
	int primaryAttack();
	void addPotion();
	void addStrongPotion();
	void addPowerPotion();
	void addMaxPotion();
	void inventory();
};

class Warrior: public Character{
public:
	Warrior(string name);
};

class Wizard: public Character{
public:
	Wizard(string name);
};

class Looter: public Character{
public:
	Looter(string name);
};

#endif //CHARACTER_H