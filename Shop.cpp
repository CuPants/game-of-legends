//============================================================================== 
// File name    : Shop.cpp
// Author       : Jeffrey Thor
// Date         : 11/22/2015
// Description  : Shop Class - Game Of Legends
// Collaborators: n/a
//==============================================================================

#include <iostream>
#include <vector>
#include "Shop.h"
#include "Character.h"

using namespace std;

Shop::Shop(){

}

void Shop::setShop(){
	string tempItems [5] = {"potion", "strong-potion", "stronger-potion", "strongest-potion", "revive"};
	shopItems.insert(shopItems.end(), tempItems, tempItems+5);
	int tempPrices [5] = {200, 400, 800, 2000, 5000};
	shopPrices.insert(shopPrices.end(), tempPrices, tempPrices+5);
}

void Shop::shop(Character *character){
	string choice;
	bool check;
	int count;
	int price;
	do{
		character->printStats();
		cout << "\t\t\t      WELCOME TO THE SHOP" << endl;
		cout << "================================================================================" << endl;
		for(int i = 0; i < shopItems.size(); i++)
			cout << "\"" << shopItems[i] << "\" x" << shopPrices[i] << " gold     ";
		cout << endl;
		cout << "================================================================================" << endl << endl;

		cout << "What would you like to purchase? Or you may \"leave\"." << endl << endl;
		cout << character->getName() << ": ";
		cin.clear();
		getline(cin, choice);
		cout << endl;
		for(int i = 0; i != shopItems.size(); i++){
			if(shopItems[i] == choice){
				check = true;
				price = shopPrices[i];
			}
		}
		if(choice == "leave"){
			break;
		}
		else if(check){
			check = false;
			cout << "How many would you like? \"1\", \"2\", \"3\",...\"99\"" << endl << endl;
			cout << character->getName() << ": ";
			cin >> count;
			cout << endl;
			for(int i = 1; i <= 99; i++){
				if(count == i)
					check = true;
			}
			if(check){
				if(price * count > character->getGold())
					cout << "You don't have enough gold!" << endl << endl;
				else{
					for(int i = 0; i < count; i++){
						character->addItem(choice);
					}
					character->setGold(character->getGold() - count * price);
					cout << "Here you go, " << count << " " << choice << "(s)." << endl << endl;
					cout << "Press enter to return to the shop" << endl;
					cin.ignore(10000, '\n');
					cin.get();
				}
			}
			else
				cout << "I'm sorry, that's not an option." << endl << endl;
		}
		else
			cout << "I'm sorry, that isn't an option." << endl << endl;
	}while(choice != "leave");
}