//============================================================================== 
// File name    : main.cpp
// Author       : Jeffrey Thor
// Date         : 9/23/2015
// Description  : Game of Legends - Land of Lerocia
// Collaborators: David Thor
//==============================================================================

//libraries
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <chrono>
//classes
#include "Character.h"
#include "Enemy.h"
#include "Battle.h"
#include "Village.h"
#include "Home.h"

using namespace std;

//function declarations
void runGame();
void printBanner();
void error();
void printLine();

//main
int main(){
    runGame();
    return 0;
}

void runGame(){
    //variable declarations
    const string SAVES = "saves.txt";
    string choice, name, characterType, fileName, fileCharacterType, fileItem, lineType;
    int fileExperience, fileLevel, fileHealth, fileMaxHealth, fileGold, enemySelection;
    bool load, fileAlive, firstPass = true, quit;
    srand(time(0));
    locale loc;
    ifstream fileIn;
    ofstream fileOut;
    Character *character;
    Enemy *enemy;
    Battle battle;
    Village village;
    Home home;
    //introductory banner
    printBanner();
    cout << endl;

    do{
        cout << "\"new\"" << endl;
        cout << "\"load\"" << endl << endl;
        getline(cin, choice);
        cout << endl;
        if(choice == "new"){
            load = false;
            break;
        }
        else if(choice == "load"){
            firstPass = false;
            fileIn.open(SAVES.c_str());
            fileIn >> fileCharacterType;
            if(fileCharacterType == "warrior"){
                Warrior myWarrior(name, characterType);
                character = &myWarrior;
            }
            else if(fileCharacterType == "wizard"){
                Wizard myWizard(name, characterType);
                character = &myWizard;
            }
            else if(fileCharacterType == "looter"){
                Looter myLooter(name, characterType);
                character = &myLooter;
            }
            else{
                cout << "I'm sorry, there doesn't seem to be a saved file" << endl << endl;
                continue;
            }
            fileIn >> fileName;
            fileIn >> fileExperience;
            fileIn >> fileLevel;
            fileIn >> fileHealth;
            fileIn >> fileMaxHealth;
            fileIn >> fileGold;
            fileIn >> fileAlive;
            while(fileIn.good()){
                fileIn >> fileItem;
                character->addItem(fileItem);
            }
            character->setStats(fileCharacterType, fileName, fileExperience, fileLevel, fileHealth, fileMaxHealth, fileGold, fileAlive);
            load = true;
            fileIn.close();
        }
        else{
            error();
        }
    }while(choice != "new" && choice != "load");


    if(!load){

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
    }while(choice == "no");

    cout << "Hello " << name << ", and welcome to the Land of Lerocia!" << endl << endl;
    cout << "Press enter to continue" << endl;
    cin.get();
    cout << "This is a text-based game in which you will fight enemies in turn-based \nbattles, collect items and weapons, and build up your character." << endl;
    cin.get();
    cout << "To perform an action, you must type one of the commands marked in quotations.\nOtherwise, just hit enter to continue" << endl;
    cin.get();
    //list character types
    cout << "Very good! Now let's get started." << endl;
    cin.get();
    cout << "First things first, you have to choose your character." << endl;
    cin.get();
    cout << "Each has different attributes and you will be this character for the rest of \nthe game. So choose wisely." << endl;
    cin.get();
    cout << "WARRIOR:" << endl;
    cout << "The warrior is a physical fighter. His stats allow you to have extra max health \nthan the other characters." << endl;
    cout << "He has the lowest chance to miss, but also a lower critical hit rate." << endl;
    cin.get();
    cout << "WIZARD:" << endl;
    cout << "The wizard attacks using spells. His arsenal also allows the player to heal \nthemselves during battle." << endl;
    cout << "He has the highest chance to miss, but also has the highest critical hit rate." << endl;
    cin.get();
    cout << "LOOTER:" << endl;
    cout << "The looter is a physical fighter. His abilities allow you more gold and a much \nbetter chance of loot per battle." << endl;
    cout << "He has an equal miss and critical hit rate." << endl;
    cin.get();
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
    village.intro();

    }

    village.setLocations();
    character->setShop();

    do{
    quit = false;
    for (string::size_type i=0; i < (80 - character->getName().length())/2; ++i)
            cout << " ";
    for (string::size_type i=0; i < character->getName().length(); ++i)
        cout << toupper(character->getName()[i],loc);
    cout << endl;
    village.updateLocations(character->getLevel());
    character->printStats();
    village.printLocations();
    choice = village.selection(character->getName());
    enemySelection = rand()%2;
    if(choice == "home"){
        home.intro(character);
    }
    else if(choice == "path"){
        if(enemySelection == 0){
            do{
                Tank myTank("tank", character->getLevel() + (rand()%3-1));
                enemy = &myTank;
            }while(enemy->getLevel() == 0);
        }
        else if(enemySelection == 1){
            do{
                Beast myBeast("beast", character->getLevel() + (rand()%3-1));
                enemy = &myBeast;
            }while(enemy->getLevel() == 0);
        }
        if(firstPass){
            battle.intro(character, enemy);
            firstPass = false;
        }
        else
            battle.screen(character, enemy);
    }
    else if(choice == "inventory"){
        character->inventory();
    }
    else if(choice == "shop"){
        character->shop();
    }
    else if(choice == "river"){
        if(enemySelection == 0){
            do{
                Tank myTank("tank", character->getLevel() + (rand()%3-1));
                enemy = &myTank;
            }while(enemy->getLevel() == 0);
        }
        else if(enemySelection == 1){
            do{
                Beast myBeast("beast", character->getLevel() + (rand()%3-1));
                enemy = &myBeast;
            }while(enemy->getLevel() == 0);
        }
        if(firstPass){
            battle.intro(character, enemy);
            firstPass = false;
        }
        else
            battle.screen(character, enemy);
    }
    else if(choice == "forest"){
    }
    else if(choice == "cliff"){
    }
    else if(choice == "mountain"){
    }
    else if(choice == "save"){
        cout << "Are you sure you would like to save? This will overwrite any saved data.\n\"yes\" or \"no\"" << endl << endl;
        cout << character->getName() << ": ";
        cin >> choice;
        if(choice == "yes"){
            cout << "\nSaving..." << endl << endl;
            this_thread::sleep_for (std::chrono::seconds(2));
            character->saveState(SAVES);
            cin.ignore(10000, '\n');
            cout << "Saved. press enter to continue." << endl;
            cin.get();
        }
        else if(choice == "no"){
            continue;
        }
    }
    else if(choice == "quit"){
        cout << "Are you sure you would like to quit? All unsaved progress will be lost.\n\"yes\" or \"no\"" << endl << endl;
        cout << character->getName() << ": ";
        cin >> choice;
        if(choice == "yes"){
            quit = true;
        }
        else if(choice == "no"){
            continue;
        }
    }
    else{
        cout << "Input Error!" << endl;
    }

    }while(!quit);
}

void printBanner(){
    printLine();
    cout << "                                GAME OF LEGENDS                                 " << endl;
    cout << "                                     -----                                      " << endl;
    cout << "                                Land of Lerocia                                 " << endl;
    printLine();
}

void error()
{
    cout << "I'm sorry, that isn't an option" << endl << endl;
}

void printLine()
{
    for(int i = 0; i < 80; i++){
        cout << '=';
    }
    cout << endl;
}