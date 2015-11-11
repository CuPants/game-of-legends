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
	int maxHealth;
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
	string getCharacterType() const;
	int getLevel() const;
	int getHealth() const;
	int getMaxHealth() const;
	int getGold() const;
	bool getAlive() const;
	//mutator functions
	void setStats(string, string, int, int, int, int, bool);
	void setName(string);
	void setCharacterType(string);
	void setLevel(int);
	void setHealth(int);
	void setMaxHealth(int);
	void setGold(int);
	void setAlive(bool);
	//action functions
	void saveState(const string SAVES);
	void printStats();
	int primaryAttack();
	void addItem(string item);
	void useItem(string item);
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