//============================================================================== 
// File name    : Shop.h
// Author       : Jeffrey Thor
// Date         : 11/22/2015
// Description  : Shop Class - Game Of Legends
// Collaborators: n/a
//==============================================================================

#ifndef SHOP_H
#define SHOP_H

#include <string>
#include <vector>
#include "Character.h"

class Shop{
protected:
	std::vector<string> shopItems;
	std::vector<int> shopPrices;
public:
	Shop();
	void setShop();
	void shop(Character *character);
};

#endif //SHOP_H