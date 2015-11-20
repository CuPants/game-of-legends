//============================================================================== 
// File name    : Mountain.cpp
// Author       : Jeffrey Thor
// Date         : 11/17/2015
// Description  : Mountain Class - Game of Legends
// Collaborators: n/a
//==============================================================================

#include <iostream>
#include "Mountain.h"
#include "Character.h"
#include "Enemy.h"
#include "Battle.h"

using namespace std;

Mountain::Mountain(){

}

void Mountain::scene(Character *character, bool won){
	cout << "You've trained long and hard, you're strong enough to make the climb." << endl << endl;
    cout << "But what lies at the peak??" << endl;
	cout << "Press enter to fight." << endl;
	cin.get();
	int enemySelection = rand() % 6;
	Enemy *enemy;
	Battle battle;
    if(enemySelection == 0){
        Tank tank("tank", character->getLevel() + (rand()%3-1));
        enemy = &tank;
    }
    else if(enemySelection == 1){
        Beast beast("beast", character->getLevel() + (rand()%3-1));
        enemy = &beast;
    }
    else if(enemySelection == 2){
        Brute brute("brute", character->getLevel() + (rand()%3-1));
        enemy = &brute;
    }
    else if(enemySelection == 3){
        Wolf wolf("wolf", character->getLevel() + (rand()%3-1));
        enemy = &wolf;
    }
    else if(enemySelection == 4){
        Witch witch("witch", character->getLevel() + (rand()%3-1));
        enemy = &witch;
    }
    else if(enemySelection == 5){
        Ghost ghost("ghost", character->getLevel() + (rand()%3-1));
        enemy = &ghost;
    }
    else
    	cout << "Selection Error!" << endl;
    battle.screen(character, enemy, won);
}