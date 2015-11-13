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

Enemy::Enemy(){
	enemyType = "";
	level = 0;
	health = 0;
	maxHealth = 0;
	alive = false;
	srand(time(0));
}

Enemy::Enemy(string enemyType){
	this->enemyType = enemyType;
}

Tank::Tank(string enemyType) : Enemy::Enemy(enemyType){
	enemyType = "tank";
	level = 1;
	health = level*15;
	maxHealth = level*15;
	alive = true;
	criticalPoint = 20;
}

Beast::Beast(string enemyType) : Enemy::Enemy(enemyType){
	enemyType = "beast";
	level = 1;
	health = level*10;
	maxHealth = level*10;
	alive = true;
	criticalPoint = 12;
}

Enemy::~Enemy(){

}

string Enemy::getEnemyType() const{
	return enemyType;
}

int Enemy::getLevel() const{
	return level;
}

int Enemy::getHealth() const{
	return health;
}

int Enemy::getMaxHealth() const{
	return maxHealth;
}

bool Enemy::getAlive() const{
	return alive;
}

void Enemy::setHealth(int health){
	this->health = health;
}

void Enemy::setAlive(bool alive){
	this->alive = alive;
}

void Enemy::printStats(){
	cout << "================================================================================" << endl;
	cout << "Enemy: " << enemyType << " LEVEL: " << level << " HEALTH: " << health << "/" << maxHealth << " ALIVE: " << boolalpha << alive << endl;
	cout << "================================================================================" << endl;
}

int Enemy::primaryAttack(){
    int damage = 0;
    if (rand() % criticalPoint == 0){
        cout << "Miss!" << endl;
        cout << enemyType << " did 0 points of damage" << endl << endl;
        return 0;
    }
    else if (rand() % criticalPoint == 0){
        cout << "Critical hit!" << endl;
        damage = (rand() % (level * 2) + (level * level)) * 2;
        cout << enemyType << " did " << damage << " point(s) of damage" << endl << endl;
        return damage;
    }
    else{
    	cout << "Hit!" << endl;
        damage = rand() % (level * 2) + (level * level);
        cout << enemyType << " did " << damage << " point(s) of damage" << endl << endl;
        return damage;
    }
}