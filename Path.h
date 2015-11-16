//============================================================================== 
// File name    : Path.h
// Author       : Jeffrey Thor
// Date         : 11/15/2015
// Description  : Path Class - Game of Legends
// Collaborators: n/a
//==============================================================================

#ifndef PATH_H
#define PATH_H

#include <string>
#include "Character.h"
using namespace std;

class Path{
public:
	Path();
	void firstLocation(Character *character);
	void secondLocation(Character *character);
	void thirdLocation(Character *character);
};

#endif //PATH_H