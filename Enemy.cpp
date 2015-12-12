//============================================================================== 
// File name    : Enemy.cpp
// Author       : Jeffrey Thor
// Date         : 11/12/2015
// Description  : Enemy Class - Game of Legends
// Collaborators: n/a
//==============================================================================

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Enemy.h"

using namespace std;

//Default Constructor
Enemy::Enemy(){
	enemyType = "";
	level = 0;
	health = 0;
	maxHealth = 0;
	alive = false;
	srand(time(0));
}

/**
 * Constructor. Sets all of the data members.
 *
 * @param enemyType The enemies type.
 * @param level The enemy's level.
 */
Enemy::Enemy(string enemyType, int level){
	this->enemyType = enemyType;
	this->level = level;
}

/**
 * Constructor. Sets all of the data members.
 *
 * @param enemyType The enemy's type.
 * @param level The enemy's level.
 */
Jack::Jack(string enemyType, int level) : Enemy::Enemy(enemyType, level){
	health = 150;
	maxHealth = 150;
	alive = true;
	criticalPoint = 10;
	missPoint = 10;
	damageMultiplier = 1;
}

/**
 * Constructor. Sets all of the data members.
 *
 * @param enemyType The enemy's type.
 * @param level The enemy's level.
 */
Thug::Thug(string enemyType, int level) : Enemy::Enemy(enemyType, level){
	health = 350;
	maxHealth = 350;
	alive = true;
	criticalPoint = 16;
	missPoint = 12;
	damageMultiplier = 1;
}

/**
 * Constructor. Sets all of the data members.
 *
 * @param enemyType The enemy's type.
 * @param level The enemy's level.
 */
Brawler::Brawler(string enemyType, int level) : Enemy::Enemy(enemyType, level){
	health = 420;
	maxHealth = 420;
	alive = true;
	criticalPoint = 16;
	missPoint = 14;
	damageMultiplier = 1;
}

/**
 * Constructor. Sets all of the data members.
 *
 * @param enemyType The enemy's type.
 * @param level The enemy's level.
 */
Hunter::Hunter(string enemyType, int level) : Enemy::Enemy(enemyType, level){
	health = 490;
	maxHealth = 490;
	alive = true;
	criticalPoint = 3;
	missPoint = 24;
	damageMultiplier = 1.4;
}

/**
 * Constructor. Sets all of the data members.
 *
 * @param enemyType The enemy's type.
 * @param level The enemy's level.
 */
Knight::Knight(string enemyType, int level) : Enemy::Enemy(enemyType, level){
	health = level * level * level;
	maxHealth = level * level * level;
	alive = true;
	criticalPoint = 8;
	missPoint = 10;
	damageMultiplier = 2.0;
}

/**
 * Constructor. Sets all of the data members.
 *
 * @param enemyType The enemy's type.
 * @param level The enemy's level.
 */
Orc::Orc(string enemyType, int level) : Enemy::Enemy(enemyType, level){
	health = 3000;
	maxHealth = 3000;
	alive = true;
	criticalPoint = 10;
	missPoint = 10;
	damageMultiplier = 2.4;
}

/**
 * Constructor. Sets all of the data members.
 *
 * @param enemyType The enemy's type.
 * @param level The enemy's level.
 */
Guardian::Guardian(string enemyType, int level) : Enemy::Enemy(enemyType, level){
	health = 5000;
	maxHealth = 5000;
	alive = true;
	criticalPoint = 6;
	missPoint = 8;
	damageMultiplier = 2.6;
}

/**
 * Constructor. Sets all of the data members.
 *
 * @param enemyType The enemy's type.
 * @param level The enemy's level.
 */
KingJack::KingJack(string enemyType, int level) : Enemy::Enemy(enemyType, level){
	health = 20000;
	maxHealth = 20000;
	alive = true;
	criticalPoint = 3;
	missPoint = 18;
	damageMultiplier = 6;
}

/**
 * Constructor. Sets all of the data members.
 *
 * @param enemyType The enemy's type.
 * @param level The enemy's level.
 */
Tank::Tank(string enemyType, int level) : Enemy::Enemy(enemyType, level){
	health = level*level*16;
	maxHealth = level*level*16;
	alive = true;
	criticalPoint = 20;
	missPoint = 20;
	damageMultiplier = .8;
}

/**
 * Constructor. Sets all of the data members.
 *
 * @param enemyType The enemy's type.
 * @param level The enemy's level.
 */
Beast::Beast(string enemyType, int level) : Enemy::Enemy(enemyType, level){
	health = level*level*10;
	maxHealth = level*level*10;
	alive = true;
	criticalPoint = 12;
	missPoint = 12;
	damageMultiplier = 1.2;
}

/**
 * Constructor. Sets all of the data members.
 *
 * @param enemyType The enemy's type.
 * @param level The enemy's level.
 */
Brute::Brute(string enemyType, int level) : Enemy::Enemy(enemyType, level){
	health = level*level*18;
	maxHealth = level*level*18;
	alive = true;
	criticalPoint = 16;
	missPoint = 20;
	damageMultiplier = 1.6;
}

/**
 * Constructor. Sets all of the data members.
 *
 * @param enemyType The enemy's type.
 * @param level The enemy's level.
 */
Wolf::Wolf(string enemyType, int level) : Enemy::Enemy(enemyType, level){
	health = level*level*15;
	maxHealth = level*level*15;
	alive = true;
	criticalPoint = 5;
	missPoint = 16;
	damageMultiplier = 1.8;
}

/**
 * Constructor. Sets all of the data members.
 *
 * @param enemyType The enemy's type.
 * @param level The enemy's level.
 */
Witch::Witch(string enemyType, int level) : Enemy::Enemy(enemyType, level){
	health = level*level*12;
	maxHealth = level*level*12;
	alive = true;
	criticalPoint = 24;
	missPoint = 2;
	damageMultiplier = 2.6;
}

/**
 * Constructor. Sets all of the data members.
 *
 * @param enemyType The enemy's type.
 * @param level The enemy's level.
 */
Ghost::Ghost(string enemyType, int level) : Enemy::Enemy(enemyType, level){
	health = level*level;
	maxHealth = level*level;
	alive = true;
	criticalPoint = 24;
	missPoint = 3;
	damageMultiplier = 12;
}

//Deconstructor
Enemy::~Enemy(){

}

//Gets enemy's type.
string Enemy::getEnemyType() const{
	return enemyType;
}
//Gets enemy's level.
int Enemy::getLevel() const{
	return level;
}
//Gets enemy's health.
int Enemy::getHealth() const{
	return health;
}
//Gets enemy's max health.
int Enemy::getMaxHealth() const{
	return maxHealth;
}
//Gets enemy's state of life.
bool Enemy::getAlive() const{
	return alive;
}
//Sets enemy's level.
void Enemy::setLevel(int level){
	this->level = level;
}
//Sets enemy's health.
void Enemy::setHealth(int health){
	this->health = health;
}
//Sets enemy's state of life.
void Enemy::setAlive(bool alive){
	this->alive = alive;
}

/**
 * Prints the enemy's stats.
 */
void Enemy::printStats(){
	cout << "================================================================================" << endl;
	cout << "ENEMY: " << enemyType << " LEVEL: " << level << " HEALTH: " << health << "/" << maxHealth << endl;
	cout << "================================================================================" << endl;
}

/**
 * Calculates damage of the enemy's primary attack.
 *
 * @param temp A temp string variable that holds "miss", "hit", or "critical".
 * @return The damage of the attack.
 */
int Enemy::primaryAttack(string &temp){
    int damage = 0;
    if (rand() % missPoint == 0){
    	temp = "miss";
        return damage;
    }
    else if (rand() % criticalPoint == 0){
    	temp = "critical";
        damage = ((rand() % (level * 2) + (level * level)) * damageMultiplier) * 2;
        return damage;
    }
    else{
    	temp = "hit";
        damage = (rand() % (level * 2) + (level * level)) * damageMultiplier;
        return damage;
    }
}

/**
 * Prints the outcome of the enemy's primary attack.
 *
 * @param temp A temp string variable that holds "miss", "hit", or "critical".
 * @param damage The damage of the attack.
 */
void Enemy::printAttack(string temp, int damage){
	if(temp == "miss"){
		cout << "Miss!" << endl;
        cout << enemyType << " did 0 points of damage" << endl << endl;
	}
	else if(temp == "critical"){
		cout << "Critical hit!" << endl;
		cout << enemyType << " did " << damage << " point(s) of damage" << endl << endl;
	}
	else if(temp == "hit"){
		cout << "Hit!" << endl;
		cout << enemyType << " did " << damage << " point(s) of damage" << endl << endl;
	}
}