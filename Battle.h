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
	Battle();
	void intro(Character *character, Enemy *enemy);
	void screen(Character *character, Enemy *enemy);
	void attackChoice(Character *character, Enemy *enemy, string choice);
};

#endif //BATTLE_H