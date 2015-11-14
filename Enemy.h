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

class Tank: public Enemy{
public:
	Tank(string enemyType, int level);
};

class Beast: public Enemy{
public:
	Beast(string enemyType, int level);
};

#endif //ENEMY_H