//============================================================================== 
// File name    : Character.h
// Author       : Jeffrey Thor
// Date         : 11/16/2015
// Description  : River Class - Game of Legends
// Collaborators: n/a
//==============================================================================

#ifndef RIVER_H
#define RIVER_H

#include <string>
#include "Character.h"
using namespace std;

class River{
public:
	River();
	void scene(Character *character, bool &firstPass, bool won);
};

#endif //CHARACTER_H