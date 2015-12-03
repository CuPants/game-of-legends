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
						secondLocation(character, name);
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
						secondLocation(character, name);
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

void Path::secondLocation(Character *character, string name){
	Enemy *enemy;
	Thug thug("thug", 5);
	Brawler brawler("brawler", 6);
	Hunter hunter("hunter", 7);
	Battle battle;
	string choice;
	bool won;
	cout << "You continue down the path, leaving Jack behind. Unfortunately for you it looks\n"
		 << "like he's got some friends up the road. What could they be hiding?" << endl << endl;
	cout << "Press enter to continue." << endl;
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
			cout << "Press enter to begin the fight." << endl;
			cin.get();
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
			if(won){
				cout << "You stand above the mangled bodies of your three foes and you know you have to\n"
					 << "keep moving." << endl << endl;
				cout << "Press enter to continue." << endl;
				cin.get();
				thirdLocation(character, name);
			}
		}
		else{
			cout << "I'm sorry, that isn't an option." << endl << endl;
		}
	}while(choice != "yes" && choice != "no");
}

void Path::thirdLocation(Character *character, string name){
	Enemy *enemy;
	Knight knight1("knight", 10);
	Knight knight2("knight", 11);
	Battle battle;
	string choice;
	bool won;
	do{
		cout << "This isn't going to be easy, but you know something's definitely going on up by\n"
		 	 << "the castle. You may not survive the journey, but should you keep going to\n"
		 	 << "investigate? \"yes\" or \"no\"" << endl << endl;
		cout << character->getName() << ": ";
		getline(cin, choice);
		cout << endl;
		if(choice == "yes"){
			cout << "You can't turn your back to whatever's going on. Looks like there are a couple\n"
				 << "knights from the castle up ahead. As you approach them you realize they aren't\n"
				 << "from Lerocia, looks like trouble." << endl << endl;
			cout << "Press enter to begin the fight." << endl;
			cin.get();
			enemy = &knight1;
			battle.screen(character, enemy, won);
			if(won){
				enemy = &knight2;
				battle.screen(character, enemy, won);
			}
			if(won){
				cout << "Where did those knights come from? You have got to get to that castle, and fast." << endl << endl;
				cout << "Press enter to continue." << endl;
				cin.get();
				fourthLocation(character, name);
			}
		}
		else if(choice == "no"){
			cout << "Is the risk really woth it? Probably best to return to the village." << endl << endl;
			cout << "Press enter to return to the village." << endl;
			cin.get();
		}
		else{
			cout << "I'm sorry, that isn't an option." << endl << endl;
		}
	}while(choice != "yes" && choice != "no");
}

void Path::fourthLocation(Character *character, string name){
	Enemy *enemy;
	Orc orc("orc", 17);
	Battle battle;
	string choice;
	bool won;
	do{
		cout << "You can finally see the castle gates! But looks like there's someone waiting for\n"
		 	 << "you. It looks like a giant orc! Do you dare try to take him on? \"yes\" or \"no\"" << endl << endl;
		cout << character->getName() << ": ";
		getline(cin, choice);
		cout << endl;
		if(choice == "yes"){
			cout << "Press enter to begin the fight." << endl;
			cin.get();
			enemy = &orc;
			battle.screen(character, enemy, won);
			if(won){
				cout << "He's definitely not getting back up, looks like you can head through the gate." << endl << endl;
				cout << "Press enter to continue." << endl;
				cin.get();
				fifthLocation(character, name);
			}
		}
		else if(choice == "no"){
			cout << "He looks way too big to get past, probably a good idea to turn back for now." << endl << endl;
			cout << "Press enter to return to the village." << endl;
			cin.get();
		}
		else{
			cout << "I'm sorry, that isn't an option." << endl << endl;
		}
	}while(choice != "yes" && choice != "no");
}

void Path::fifthLocation(Character *character, string name){
	Enemy *enemy;
	Guardian guardian1("guardian", 20);
	Guardian guardian2("guardian", 20);
	Guardian guardian3("guardian", 20);
	Battle battle;
	string choice;
	bool won;
	do{
		cout << "As you open the gate you see war raging everywhere! Fires throughout the castle\n"
			 << "and Lerocian soldiers under attack! Who's behind all of this? You have to find\n"
			 << "out, so you run through the raging war towards the center of the castle. As you\n"
			 << "approach the throne room you see the only thing standing between you and the\n"
			 << "doorway are three massive guards. Last chance, do you fight? \"yes\" or \"no\"" << endl << endl;
		getline(cin, choice);
		cout << endl;
		if(choice == "yes"){
			cout << "You charge the first guard, you have got to make it through those doors!" << endl << endl;
			cout << "Press enter to begin the fight." << endl;
			cin.get();
			enemy = &guardian1;
			battle.screen(character, enemy, won);
			if(won){
				enemy = &guardian2;
				battle.screen(character, enemy, won);
			}
			if(won){
				enemy = &guardian3;
				battle.screen(character, enemy, won);
			}
			if(won){
				cout << "That's it, the guards are dead. It's time to see who's behind all of this." << endl << endl;
				cout << "Press enter to continue." << endl;
				cin.get();
				sixthLocation(character, name);
			}
		}
		else if(choice == "no"){
			cout << "You're not ready for this yet." << endl << endl;
			cout << "Press enter to return to the village." << endl;
			cin.get();
		}
		else{
			cout << "I'm sorry, that isn't an option." << endl << endl;
		}
	}while(choice != "yes" && choice != "no");
}

void Path::sixthLocation(Character *character, string name){
	Enemy *enemy;
	KingJack jack("jack", 25);
	Battle battle;
	string choice;
	bool won;
	do{
		cout << "This is it, last chance to turn back. Do you enter the room? \"yes\" or \"no\"" << endl << endl;
		getline(cin, choice);
		cout << endl;
		if(choice == "yes"){
			cout << "You open the massive doors, look up, and hear a familiar voice..." << endl << endl;
			if(name != character->getName()){
				cout << "Jack: Hello " << name << ". Or should I say, " << character->getName() << "." << endl;
				cout << "It's Jack! He was supposed to be long dead!" << endl << endl;
				cout << "Jack: Really now, do you think I'm dumb enough to believe the fake name you gave\nme?" << endl << endl;
			}
			else{
				cout << "Jack: Hello " << character->getName() << ". I've been expecting you." << endl << endl;
			}
			cout << "Press enter to continue." << endl;
			cin.get();
			cout << "Jack: Now you're probably wondering how I'm still alive. Well to be honest I let\n"
				 << "you beat me the first time we fought. I was wondering how long it would take you\n"
				 << "to get here. Now that I've killed the king and taken over the kingdom, I am the\n"
				 << "ruler of the Land of Lerocia!" << endl << endl;
			cout << "You see the king laying dead at his feet." << endl << endl;
			cout << "Press enter to continue." << endl;
			cin.get();
			cout << "Jack: Now don't say a word " << character->getName() << ", I know why you're here.\n"
				 << "You think you can kill me. Too bad I'm not going to take it easy this time." << endl << endl;
			cout << "Press enter to begin the fight." << endl;
			cin.get();
			enemy = &jack;
			battle.screen(character, enemy, won);
			if(won){
				cout << "Jack: No! How could this be, I conquered an entire kingdom and lose to you!" << endl << endl;
				cout << "You watch Jack take his last breath as you walk out of the throne room. The\n"
					 << "rebellion begins to look up as they see you, victorious. Their leader is dead.\n"
					 << "You don't say a word, you return to the village, the war slowly dies down." << endl << endl;
				cout << "The Land of Lerocia is saved!" << endl << endl;
				cout << "Press enter to return to the village." << endl;
				cin.get();
			}
		}
		else if(choice == "no"){
			cout << "Better make sure we're ready for this first." << endl << endl;
			cout << "Press enter to return to the village." << endl;
			cin.get();
		}
		else{
			cout << "I'm sorry, that isn't an option." << endl << endl;
		}
	}while(choice != "yes" && choice != "no");
}