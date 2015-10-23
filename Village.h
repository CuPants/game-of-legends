//============================================================================== 
// File name    : Village.h
// Author       : Jeffrey Thor
// Date         : 10/22/2015
// Description  : Village Class - Game of Legends
// Collaborators: n/a
//==============================================================================

#ifndef VILLAGE_H
#define VILLAGE_H

#include <string>
#include <vector>
using namespace std;

class Village{
protected:
	std::vector<string> locations;
public:
	Village();
	~Village();
	void setLocations();
	void updateLocations(int level);
	void printLocations();
};

#endif //VILLAGE_H