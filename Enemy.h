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
	Enemy();
	Enemy(string, int);
	~Enemy();
	string getEnemyType() const;
	int getLevel() const;
	int getHealth() const;
	int getMaxHealth() const;
	bool getAlive() const;
	void setEnemyType(string);
	void setLevel(int);
	void setHealth(int);
	void setMaxHealth(int);
	void setAlive(bool);
	void printStats();
	int primaryAttack(string &temp);
	void printAttack(string, int);
};

class Jack: public Enemy{
public:
	Jack(string enemyType, int level);
};

class Thug: public Enemy{
public:
	Thug(string enemyType, int level);
};

class Brawler: public Enemy{
public:
	Brawler(string enemyType, int level);
};

class Hunter: public Enemy{
public:
	Hunter(string enemyType, int level);
};

class Knight: public Enemy{
public:
	Knight(string enemyType, int level);
};

class Orc: public Enemy{
public:
	Orc(string enemyType, int level);
};

class Guardian: public Enemy{
public:
	Guardian(string enemyType, int level);
};

class KingJack: public Enemy{
public:
	KingJack(string enemyType, int level);
};

class Tank: public Enemy{
public:
	Tank(string enemyType, int level);
};

class Beast: public Enemy{
public:
	Beast(string enemyType, int level);
};

class Brute: public Enemy{
public:
	Brute(string enemyType, int level);
};

class Wolf: public Enemy{
public:
	Wolf(string enemyType, int level);
};

class Witch: public Enemy{
public:
	Witch(string enemyType, int level);
};

class Ghost: public Enemy{
public:
	Ghost(string enemyType, int level);
};

#endif //ENEMY_H