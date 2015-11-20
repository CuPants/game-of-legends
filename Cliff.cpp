//============================================================================== 
// File name    : Cliff.cpp
// Author       : Jeffrey Thor
// Date         : 11/17/2015
// Description  : Cliff Class - Game of Legends
// Collaborators: n/a
//==============================================================================

#include <iostream>
#include "Cliff.h"
#include "Character.h"
#include "Enemy.h"
#include "Battle.h"

using namespace std;

Cliff::Cliff(){

}

void Cliff::scene(Character *character, bool won){
	cout << "A little ways south of the village, you've heard rumors of the haunted cliff." << endl << endl;
    cout << "Looks like the rumors may be true!" << endl;
	cout << "Press enter to fight." << endl;
	cin.get();
	int enemySelection = rand() % 2;
	Enemy *enemy;
	Battle battle;
    if(enemySelection == 0){
        if(character->getLevel() > 21){
            Witch witch("witch", 21);
            enemy = &witch;
        }
    	else{
        	Witch witch("witch", character->getLevel() + (rand()%3-1));
        	enemy = &witch;
    	}
    }
    else if(enemySelection == 1){
        if(character->getLevel() > 21){
            Ghost ghost("ghost", 21);
            enemy = &ghost;
        }
        else{
            Ghost ghost("ghost", character->getLevel() + (rand()%3-1));
            enemy = &ghost;
        }
    }
    else
    	cout << "Selection Error!" << endl;
    battle.screen(character, enemy, won);
}