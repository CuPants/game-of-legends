//============================================================================== 
// File name    : Forest.cpp
// Author       : Jeffrey Thor
// Date         : 11/17/2015
// Description  : Forest Class - Game of Legends
// Collaborators: n/a
//==============================================================================

#include <iostream>
#include "Forest.h"
#include "Character.h"
#include "Enemy.h"
#include "Battle.h"

using namespace std;

Forest::Forest(){

}

void Forest::scene(Character *character, bool won){
	cout << "I guess you're more comfortable with leaving the village now, the forest is\n"
         << "seeming a little ominous." << endl << endl;
    cout << "What's that sound??" << endl;
	cout << "Press enter to fight." << endl;
	cin.get();
	int enemySelection = rand() % 2;
	Enemy *enemy;
	Battle battle;
    if(enemySelection == 0){
        if(character->getLevel() > 16){
            Brute brute("brute", 16);
            enemy = &brute;
        }
        else{
        	Brute brute("brute", character->getLevel() + (rand()%3-1));
        	enemy = &brute;
        }
    }
    else if(enemySelection == 1){
        if(character->getLevel() > 16){
            Wolf wolf("wolf", 16);
            enemy = &wolf;
        }
        else{
            Wolf wolf("wolf", character->getLevel() + (rand()%3-1));
            enemy = &wolf;
        }
    }
    else
    	cout << "Selection Error!" << endl;
    battle.screen(character, enemy, won);
}