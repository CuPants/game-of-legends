//============================================================================== 
// File name    : main.cpp
// Author       : Jeffrey Thor
// Date         : 9/23/2015
// Description  : Game of Legends - Land of Lerocia
// Collaborators: David Thor
//==============================================================================

#include <iostream>
//#include <unistd.h>
//usleep(1000000);
#include "Character.h"
#include "Village.h"

using namespace std;

//function declarations
void error();
void printLine();

int main(){
    //variable declarations
    string choice, name, characterType;
    Character *character;
    Village *village;
    //introductory banner
    printLine();
    cout << "                                GAME OF LEGENDS                                 " << endl;
    cout << "                                     -----                                      " << endl;
    cout << "                                Land of Lerocia                                 " << endl;
    printLine();
    cout << endl;

    cout << "Welcome to Game of Legends - Land of Lerocia, please enter your name." << endl << endl;

    //enter and confirm users name
    do{
        cout << "Name: ";
        getline(cin, name);
        cout << endl;

        do{
            cout << "So your name is " << name << "? \"yes\" or \"no\"" << endl << endl;

            cout << name << ": ";
            getline(cin, choice);
            cout << endl;

            if(choice != "yes" && choice != "no"){
                error();
            }
        }while(choice != "yes" && choice != "no");

        if(choice == "yes")
            break;
        else if(choice == "no"){
            cout << "Please enter your name." << endl << endl;
            name = "";
        }
    }while(true);

    cout << "Hello " << name << ", and welcome to the Land of Lerocia!" << endl << endl;
    cout << "This is a text-based game in which you will fight enemies in turn-based \nbattles, collect items and weapons, and build up your character." << endl << endl;

    do{
        cout << "To perform an action, you must type one of the commands marked in quotations." << endl << endl;

        cout << "\"continue\"" << endl << endl;

        cout << name << ": ";
        getline(cin, choice);
        cout << endl;
    }while(choice != "continue");

    //list character types
    cout << "Very good! Now let's get started." << endl << endl;
    cout << "First things first, you have to choose your character." << endl;
    cout << "Each has different attributes and you will be this character for the rest of \nthe game. So choose wisely." << endl << endl;

    cout << "WARRIOR:" << endl;
    cout << "The warrior is a physical fighter. His stats allow you to have extra max health \nthan the other characters." << endl;
    cout << "He has the lowest chance to miss, but also a lower critical hit rate." << endl << endl;

    cout << "WIZARD:" << endl;
    cout << "The wizard attacks using spells. His arsenal also allows the player to heal \nthemselves during battle." << endl;
    cout << "He has the highest chance to miss, but also has the highest critical hit rate" << endl << endl;

    cout << "LOOTER:" << endl;
    cout << "The looter is a physical fighter. His abilities allow you more gold and a much \nbetter chance of loot per battle." << endl;
    cout << "He has an equal miss and critical hit rate." << endl << endl;

    printLine();
    cout << "             \"warrior\"           \"wizard\"           \"looter\"              " << endl;
    printLine();
    cout << endl;
    //character selection
    do{
        cout << "Choose your character: ";
        getline(cin, characterType);
        cout << endl;

        if(characterType == "warrior"){
        	Warrior myWarrior(name, characterType);
        	character = &myWarrior;
        }
        else if(characterType == "wizard"){
        	Wizard myWizard(name, characterType);
        	character = &myWizard;
        }
        else if(characterType == "looter"){
        	Looter myLooter(name, characterType);
        	character = &myLooter;
        }
        else{
            error();
            continue;
        }

        character->printStats();

        do{
            cout << "So you want to be a " << characterType << "? \"yes\" or \"no\"" << endl << endl;
            cout << name << ": ";
            getline(cin, choice);
            cout << endl;
            if (choice == "yes")
                break;
            else if (choice == "no")
                characterType = "";
            else
                error();
        }while(choice != "yes" && choice != "no");
    }while(characterType != "warrior" && characterType != "wizard" && characterType != "looter");

    cout << "Let your journey begin!" << endl << endl;

    Village myVillage;
    village = &myVillage;

    village->setLocations();
    village->printLocations();

    return 0;
}

void error()
{
    cout << "I'm sorry, that isn't an option" << endl << endl;
}

void printLine()
{
    cout << "================================================================================" << endl;
}