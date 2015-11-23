//============================================================================== 
// File name    : Path.cpp
// Author       : Jeffrey Thor
// Date         : 11/15/2015
// Description  : Path Class - Game of Legends
// Collaborators: n/a
//==============================================================================

#include <iostream>
#include "Battle.h"
#include "Path.h"
#include "Character.h"
#include "Enemy.h"

using namespace std;

Path::Path(){

}

void Path::firstLocation(Character *character){
	Enemy *enemy;
	Jack jack("jack", 3);
    enemy = &jack;
	Battle battle;
	string name, choice;
	bool won;
	cout << "As you begin to leave the village, you come across a man standing on the side of\n"
		 << "the path. He begins to speak to you as you approach." << endl << endl;
	cout << "Press enter to continue." << endl;
	cin.get();
	cout << "Stranger: Hey there, what's your name?" << endl << endl;
	cout << character->getName() << ": ";
	getline(cin, name);
	do{
		cout << "\nStranger: Nice to meet you " << name << ". My name's Jack. Are you headed\n"
		 	 << "to the Lerocian Castle? \"yes\" or \"no\"" << endl << endl;
		cout << character->getName() << ": ";
		
		getline(cin, choice);
		cout << endl;
		if(choice == "yes"){
			do{
			cout << "Jack: I wouldn't recommend it. I've gotten word that they're not letting anyone\n"
				 << "near it today, not quite sure why. You'd be wasting your time to go, I'd say\n"
				 << "just turn around now. \"yes\" or \"no\"" << endl << endl;
				cout << character->getName() << ": ";
				
				getline(cin, choice);
				cout << endl;
				if(choice == "yes"){
					cout << "Jack: Good choice, run along now " << name << "." << endl << endl;
					cout << "Press enter to return to the village." << endl;
				 	
				 	cin.get();
				}
				else if(choice == "no"){
					cout << "Jack: I didn't want to have to do this, but I can't let you go any further." << endl << endl;
					cout << "Jack begins to charge you! You have no choice but to defend yourself!" << endl;
					cout << "Press enter to begin the fight." << endl;
                	battle.screen(character, enemy, won);
                	if(won){
                		cout << "Jack: Stop stop, you win! You have no idea what you've just done. But there's no\n"
		 				 	 << "hope for you, you'll never even come close to that castle." << endl << endl;
						cout << "Press enter to continue." << endl;
						cin.get();
						secondLocation(character);
					}
				}
				else{
					cout << "I'm sorry, that isn't an option." << endl << endl;
				}
			}while(choice != "yes" && choice != "no");
		}
		else if(choice == "no"){
			do{
				cout << "\nJack: Well this path leads straight there, so shouldn't you head back the other\n"
				 	 << "way now? \"yes\" or \"no\"" << endl << endl;
				cout << character->getName() << ": ";
				
				getline(cin, choice);
				if(choice == "yes"){
					cout << "\nJack: Good choice, be safe now " << name << "." << endl << endl;
					cout << "Press enter to return to the village." << endl;
				 	
				 	cin.get();
				}
				else if(choice == "no"){
					cout << "\nJack: I'm sorry but I actually can't let you do that." << endl << endl;
					cout << "Jack draws a sword on you, you have no choice but to fight back!" << endl;
					cout << "Press enter to begin the fight." << endl;
					battle.screen(character, enemy, won);
					if(won){
						cout << "Jack: Stop stop, you win! You have no idea what you've just done. But there's no\n"
		 				 	 << "hope for you, you'll never even come close to that castle." << endl << endl;
						cout << "Press enter to continue." << endl;
						cin.get();
						secondLocation(character);
					}
				}
				else{
					cout << "I'm sorry, that isn't an option." << endl << endl;
				}
			}while(choice != "yes" && choice != "no");
		}
		else{
			cout << "I'm sorry, that isn't an option." << endl << endl;
		}
	}while(choice != "yes" && choice != "no");
}

void Path::secondLocation(Character *character){
	Enemy *enemy;
	Thug thug("thug", 5);
	Brawler brawler("brawler", 6);
	Hunter hunter("hunter", 7);
	Battle battle;
	string choice;
	bool won;
	cout << "You continue down the path, leaving Jack behind. Unfortunately for you it looks\n"
		 << "like he's got some friends up the road. What could they be hiding?" << endl << endl;
	cout << "Press enter to continue" << endl;
	
	cin.get();
	do{
		cout << "It's not too late to turn back, would you like to return to the village?\n"
		 	 << "\"yes\" or \"no\"" << endl << endl;
		cout << character->getName() << ": ";
		
		getline(cin, choice);
		cout << endl;
		if(choice == "yes"){
			cout << "Safe decision, press enter to return to the village." << endl;
			
			cin.get();
		}
		else if(choice == "no"){
			cout << "Confident choice, the people on the path approach you quickly, better prepare\n"
				 << "for another battle." << endl << endl;
			cout << "Press enter to begin the fight" << endl;
    		enemy = &thug;
			battle.screen(character, enemy, won);
			if(won){
				enemy = &brawler;
				
				battle.screen(character, enemy, won);
			}
			if(won){
				enemy = &hunter;
				
				battle.screen(character, enemy, won);
			}

		}
		else{

		}
	}while(choice != "yes" && choice != "no");
}

void Path::thirdLocation(Character *character){

}