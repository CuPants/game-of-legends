//============================================================================== 
// File name    : River.cpp
// Author       : Jeffrey Thor
// Date         : 11/16/2015
// Description  : River Class - Game of Legends
// Collaborators: n/a
//==============================================================================

#include <iostream>
#include "River.h"
#include "Character.h"
#include "Enemy.h"
#include "Battle.h"

using namespace std;

River::River(){

}

void River::scene(Character *character, bool &firstPass, bool won){
	cout << "You wander out to the river right outside the village, as you get to the water\n"
		 << "you begin to hear strange noises." << endl << endl;
	cout << "Watch out!" << endl;
	cout << "Press enter to fight." << endl;
	cin.get();
	int enemySelection = rand() % 2;
	Enemy *enemy;
	Battle battle;
    if(enemySelection == 0){
    	if(character->getLevel() > 11){
    		Tank tank("tank", 11);
        	enemy = &tank;
    	}
    	else{
    		do{
        		Tank tank("tank", character->getLevel() + (rand()%3-1));
        		enemy = &tank;
    		}while(enemy->getLevel() == 0);
    	}
    }
    else if(enemySelection == 1){
    	if(character->getLevel() > 11){
    		Beast beast("beast", 11);
            enemy = &beast;
    	}
    	else{
        	do{
            	Beast beast("beast", character->getLevel() + (rand()%3-1));
            	enemy = &beast;
        	}while(enemy->getLevel() == 0);
        }
    }
    else
    	cout << "Selection Error!" << endl;
    if(firstPass){
        battle.intro(character, enemy, won);
        firstPass = false;
    }
    else
        battle.screen(character, enemy, won);
}