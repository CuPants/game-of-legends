//============================================================================== 
// File name    : Cliff.h
// Author       : Jeffrey Thor
// Date         : 11/17/2015
// Description  : Cliff Class - Game of Legends
// Collaborators: n/a
//==============================================================================

#ifndef CLIFF_H
#define CLIFF_H

#include <string>
#include "Character.h"
using namespace std;

class Cliff{
public:
	Cliff();
	void scene(Character *character, bool won);
};

#endif //CLIFF_H