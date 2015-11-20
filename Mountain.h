//============================================================================== 
// File name    : Mountain.h
// Author       : Jeffrey Thor
// Date         : 11/18/2015
// Description  : Mountain Class - Game of Legends
// Collaborators: n/a
//==============================================================================

#ifndef MOUNTAIN_H
#define MOUNTAIN_H

#include <string>
#include "Character.h"
using namespace std;

class Mountain{
public:
	Mountain();
	void scene(Character *character, bool won);
};

#endif //MOUNTAIN_H