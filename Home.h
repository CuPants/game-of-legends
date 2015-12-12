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
	//default constructor
	Home();
	//text that appears when player returns home
	void intro(Character *character);
	//refills the players health
	void rest(Character *character);
};

#endif //HOME_H