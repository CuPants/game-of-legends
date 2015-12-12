//============================================================================== 
// File name    : Battle.h
// Author       : Jeffrey Thor
// Date         : 11/12/2015
// Description  : Battle Class - Game of Legends
// Collaborators: n/a
//==============================================================================

#ifndef BATTLE_H
#define BATTLE_H

#include <string>
#include "Character.h"
#include "Enemy.h"
using namespace std;

class Battle{
public:
	//default constructor
	Battle();
	//introduces and describes battles
	void intro(Character *character, Enemy *enemy, bool &won);
	//screen displayed during a battle
	void screen(Character *character, Enemy *enemy, bool &won);
	//player selects their attack
	void attackChoice(Character *character, Enemy *enemy, string choice, bool &validChoice, bool &over, bool &won);
};

#endif //BATTLE_H