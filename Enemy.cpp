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

Enemy::Enemy(string enemyType, int level){
	this->enemyType = enemyType;
	this->level = level;
}

Jack::Jack(string enemyType, int level) : Enemy::Enemy(enemyType, level){
	health = 150;
	maxHealth = 150;
	alive = true;
	criticalPoint = 10;
	missPoint = 10;
	damageMultiplier = 1;
}

Thug::Thug(string enemyType, int level) : Enemy::Enemy(enemyType, level){
	health = 350;
	maxHealth = 350;
	alive = true;
	criticalPoint = 16;
	missPoint = 12;
	damageMultiplier = 1;
}

Brawler::Brawler(string enemyType, int level) : Enemy::Enemy(enemyType, level){
	health = 420;
	maxHealth = 420;
	alive = true;
	criticalPoint = 16;
	missPoint = 14;
	damageMultiplier = 1;
}

Hunter::Hunter(string enemyType, int level) : Enemy::Enemy(enemyType, level){
	health = 490;
	maxHealth = 490;
	alive = true;
	criticalPoint = 3;
	missPoint = 24;
	damageMultiplier = 1.4;
}

Tank::Tank(string enemyType, int level) : Enemy::Enemy(enemyType, level){
	health = level*level*16;
	maxHealth = level*level*16;
	alive = true;
	criticalPoint = 20;
	missPoint = 20;
	damageMultiplier = .8;
}

Beast::Beast(string enemyType, int level) : Enemy::Enemy(enemyType, level){
	health = level*level*10;
	maxHealth = level*level*10;
	alive = true;
	criticalPoint = 12;
	missPoint = 12;
	damageMultiplier = 1.2;
}

Brute::Brute(string enemyType, int level) : Enemy::Enemy(enemyType, level){
	health = level*level*18;
	maxHealth = level*level*18;
	alive = true;
	criticalPoint = 16;
	missPoint = 20;
	damageMultiplier = 1.6;
}

Wolf::Wolf(string enemyType, int level) : Enemy::Enemy(enemyType, level){
	health = level*level*15;
	maxHealth = level*level*15;
	alive = true;
	criticalPoint = 5;
	missPoint = 16;
	damageMultiplier = 1.8;
}

Witch::Witch(string enemyType, int level) : Enemy::Enemy(enemyType, level){
	health = level*level*12;
	maxHealth = level*level*12;
	alive = true;
	criticalPoint = 24;
	missPoint = 2;
	damageMultiplier = 2.6;
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

void Enemy::setLevel(int level){
	this->level = level;
}

void Enemy::setHealth(int health){
	this->health = health;
}

void Enemy::setAlive(bool alive){
	this->alive = alive;
}

void Enemy::printStats(){
	cout << "================================================================================" << endl;
	cout << "ENEMY: " << enemyType << " LEVEL: " << level << " HEALTH: " << health << "/" << maxHealth << endl;
	cout << "================================================================================" << endl;
}

int Enemy::primaryAttack(string &temp){
    int damage = 0;
    if (rand() % missPoint == 0){
    	temp = "miss";
        return damage;
    }
    else if (rand() % criticalPoint == 0){
    	temp = "critical";
        damage = (rand() % (level * 2) + (level * level)) * 2;
        return damage;
    }
    else{
    	temp = "hit";
        damage = rand() % (level * 2) + (level * level);
        return damage;
    }
}

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