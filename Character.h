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
	int experience;
	int level;
	int health;
	int maxHealth;
	int gold;
	bool alive;
	int criticalPoint;
	int missPoint;
	float damageMultiplier;
	string specialAttackName;
	std::vector<string> shopItems;
	std::vector<int> shopPrices;
public:
	//default constructor
	Character();
	//overload constructor
	Character(string, string);
	//destructor
	~Character();
	//accessor methods
	string getName() const;
	string getCharacterType() const;
	int getExperience() const;
	int getLevel() const;
	int getHealth() const;
	int getMaxHealth() const;
	int getGold() const;
	bool getAlive() const;
	string getSpecialAttackName() const;
	//mutator methods
	void setStats(string, string, int, int, int, int, int, bool);
	void setName(string);
	void setCharacterType(string);
	void setExperience(int);
	void setLevel(int);
	void setHealth(int);
	void setMaxHealth(int);
	void setGold(int);
	void setAlive(bool);
	//action methods
	void saveState(const string SAVES);
	void printStats();
	void printAttacks();
	int primaryAttack();
	virtual int specialAttack();
	void addItem(string item);
	void useItem(string item, int position);
	void inventory();
	std::vector<string> items;
};

class Warrior: public Character{
public:
	Warrior(string name, string characterType);
	int specialAttack();
};

class Wizard: public Character{
public:
	Wizard(string name, string characterType);
	int specialAttack();
};

class Looter: public Character{
public:
	Looter(string name, string characterType);
	int specialAttack();
};

#endif //CHARACTER_H