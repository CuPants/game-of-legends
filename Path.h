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
	//default constructor
	Path();
	//first location on the path
	void firstLocation(Character *character);
	//second location on the path
	void secondLocation(Character *character, string name);
	//third location on the path
	void thirdLocation(Character *character, string name);
	//fourth location on the path
	void fourthLocation(Character *character, string name);
	//fifth location on the path
	void fifthLocation(Character *character, string name);
	//sixth location on the path
	void sixthLocation(Character *character, string name);
};

#endif //PATH_H