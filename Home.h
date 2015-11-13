//============================================================================== 
// File name    : Character.cpp
// Author       : Jeffrey Thor
// Date         : 10/24/2015
// Description  : Home Class - Game of Legends
// Collaborators: n/a
//==============================================================================

#ifndef HOME_H
#define HOME_H

#include <string>
#include "Character.h"
using namespace std;

class Home{
public:
	Home();
	void intro(Character *character);
	void rest(Character *character);
};

#endif //HOME_H