//============================================================================== 
// File name    : Enemy.h
// Author       : Jeffrey Thor
// Date         : 11/11/2015
// Description  : Enemy Class - Game of Legends
// Collaborators: n/a
//==============================================================================

#ifndef ENEMY_H
#define ENEMY_H

#include <string>
using namespace std;

class Enemy{
protected:
	string enemyType;
	int level;
	int health;
	int maxHealth;
	bool alive;
	int criticalPoint;
	int missPoint;
	float damageMultiplier;
public:
	//default constructor
	Enemy();
	//overload constructor
	Enemy(string, int);
	//deconstructor
	~Enemy();
	//get methods
	string getEnemyType() const;
	int getLevel() const;
	int getHealth() const;
	int getMaxHealth() const;
	bool getAlive() const;
	//set methods
	void setEnemyType(string);
	void setLevel(int);
	void setHealth(int);
	void setMaxHealth(int);
	void setAlive(bool);
	//prints enemies stats
	void printStats();
	//enemies primary attack
	int primaryAttack(string &temp);
	//prints enemies attack
	void printAttack(string, int);
};

//Jack sublcass.
class Jack: public Enemy{
public:
	Jack(string enemyType, int level);
	int specialAttack();
};

//Thug sublcass.
class Thug: public Enemy{
public:
	Thug(string enemyType, int level);
	int specialAttack();
};

//Brawler subclass.
class Brawler: public Enemy{
public:
	Brawler(string enemyType, int level);
	int specialAttack();
};

//Hunter subclass.
class Hunter: public Enemy{
public:
	Hunter(string enemyType, int level);
	int specialAttack();
};

//Knight subclass.
class Knight: public Enemy{
public:
	Knight(string enemyType, int level);
	int specialAttack();
};

//Orc subclass.
class Orc: public Enemy{
public:
	Orc(string enemyType, int level);
	int specialAttack();
};

//Guardian subclass.
class Guardian: public Enemy{
public:
	Guardian(string enemyType, int level);
	int specialAttack();
};

//King Jack subclass.
class KingJack: public Enemy{
public:
	KingJack(string enemyType, int level);
	int specialAttack();
};

//Tank subclass.
class Tank: public Enemy{
public:
	Tank(string enemyType, int level);
	int specialAttack();
};

//Beast subclass.
class Beast: public Enemy{
public:
	Beast(string enemyType, int level);
	int specialAttack();
};

//Brute subclass.
class Brute: public Enemy{
public:
	Brute(string enemyType, int level);
	int specialAttack();
};

//Wolf subclass.
class Wolf: public Enemy{
public:
	Wolf(string enemyType, int level);
	int specialAttack();
};

//Witch subclass.
class Witch: public Enemy{
public:
	Witch(string enemyType, int level);
	int specialAttack();
};
//Ghost subclass.
class Ghost: public Enemy{
public:
	Ghost(string enemyType, int level);
	int specialAttack();
};

#endif //ENEMY_H