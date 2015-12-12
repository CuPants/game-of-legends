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
	//get methods
	string getName() const;
	string getCharacterType() const;
	int getExperience() const;
	int getLevel() const;
	int getHealth() const;
	int getMaxHealth() const;
	int getGold() const;
	bool getAlive() const;
	string getSpecialAttackName() const;
	//set methods
	void setStats(string, string, int, int, int, int, int, bool);
	void setName(string);
	void setCharacterType(string);
	void setExperience(int);
	void setLevel(int);
	void setHealth(int);
	void setMaxHealth(int);
	void setGold(int);
	void setAlive(bool);
	//saves the player stats
	void saveState(const string SAVES);
	//prints the player stats
	void printStats();
	//prints the players attack options
	void printAttacks();
	//executes the players primary attack
	int primaryAttack();
	//characters special attack
	virtual int specialAttack();
	//adds item to inventory
	void addItem(string item);
	//uses an item from the inventory
	void useItem(string item, int position);
	//displays the inventory
	void inventory();
	//items vector
	std::vector<string> items;
};

//Warrior subclass.
class Warrior: public Character{
public:
	Warrior(string name, string characterType);
	int specialAttack();
};

//Wizard sublcass.
class Wizard: public Character{
public:
	Wizard(string name, string characterType);
	int specialAttack();
};

//Looter subclass.
class Looter: public Character{
public:
	Looter(string name, string characterType);
	int specialAttack();
};

#endif //CHARACTER_H