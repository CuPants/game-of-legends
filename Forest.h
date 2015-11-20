//============================================================================== 
// File name    : Forest.h
// Author       : Jeffrey Thor
// Date         : 11/17/2015
// Description  : Forest Class - Game of Legends
// Collaborators: n/a
//==============================================================================

#ifndef FOREST_H
#define FOREST_H

#include <string>
#include "Character.h"
using namespace std;

class Forest{
public:
	Forest();
	void scene(Character *character, bool won);
};

#endif //FOREST_H