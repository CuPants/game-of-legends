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
	string characterType;
	int level;
	int health;
	int gold;
	bool alive;
	int criticalPoint;
	std::vector<string> items;
	std::vector<string> shopItems;
	std::vector<int> shopPrices;
public:
	//default constructor
	Character();
	//overload constructor
	Character(string, string);
	//destructor
	~Character();
	//accessor functions
	string getName() const;
	int getLevel() const;
	int getHealth() const;
	int getGold() const;
	bool getAlive() const;
	//mutator functions
	void setName(string);
	void setLevel(int);
	void setHealth(int);
	void setGold(int);
	void setAlive(bool);
	//action functions
	void printStats();
	int primaryAttack();
	void addItem(string item);
	void inventory();
	void setShop();
	void shop();
};

class Warrior: public Character{
public:
	Warrior(string name, string characterType);
};

class Wizard: public Character{
public:
	Wizard(string name, string characterType);
};

class Looter: public Character{
public:
	Looter(string name, string characterType);
};

#endif //CHARACTER_H