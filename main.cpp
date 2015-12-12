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
//headers
#include "Character.h"
#include "Enemy.h"
#include "Battle.h"
#include "Village.h"
#include "Path.h"
#include "Home.h"
#include "Shop.h"

using namespace std;

//function declarations
void runGame();
void printBanner();
void error();
void printLine();
void riverScene(Character *character, bool &firstPass, bool won);
void forestScene(Character *character, bool won);
void cliffScene(Character *character, bool won);
void mountainScene(Character *character, bool won);

/**
 * Main. The first function the program runs.
 *
 * @return The exit status.
 */
int main(){
    runGame();
    return 0;
}

/**
 * Asks user to start new or load game, the runs accordingly.
 */
void runGame(){
    //variable declarations
    const string SAVES = "saves.txt";
    string choice, name, characterType, fileName, fileCharacterType, fileItem, lineType;
    int fileExperience, fileLevel, fileHealth, fileMaxHealth, fileGold;
    bool load, fileAlive, firstPass = true, quit, won;
    srand(time(0));
    locale loc;
    ifstream fileIn;
    ofstream fileOut;
    Character *character;
    Enemy *enemy;
    Battle battle;
    Village village;
    Path path;
    Home home;
    Shop shop;

    printBanner();
    cout << endl;

    //prompts user to start a new game or load a saved file
    do{
        cout << "\"new\"" << endl;
        cout << "\"load\"" << endl << endl;
        getline(cin, choice);
        cout << endl;
        //starts a new game
        if(choice == "new"){
            load = false;
            break;
        }
        //loads a previous save
        else if(choice == "load"){
            firstPass = false;
            fileIn.open(SAVES.c_str());
            fileIn >> fileCharacterType;
            if(fileCharacterType == "warrior"){
                // Warrior myWarrior(name, characterType);
                // character = &myWarrior;
                character = new Warrior(name, characterType);
            }
            else if(fileCharacterType == "wizard"){
                // Wizard myWizard(name, characterType);
                // character = &myWizard;
                character = new Wizard(name, characterType);
            }
            else if(fileCharacterType == "looter"){
                // Looter myLooter(name, characterType);
                // character = &myLooter;
                character = new Looter(name, characterType);
            }
            else{
                cout << "I'm sorry, there doesn't seem to be a saved file" << endl << endl;
                choice  = "";
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

    //If player starts a new game
    if(!load){
        //Prompt user for their name
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

        //Introduction to the game
        cout << "Hello " << name << ", and welcome to the Land of Lerocia!" << endl << endl;
        cout << "Press enter to continue" << endl;
        cin.get();
        cout << "This is a text-based game in which you will fight enemies in turn-based\n"
             << "battles, collect items and weapons, and build up your character." << endl;
        cin.get();
        cout << "To perform an action, you must type one of the commands marked in quotations.\n"
             << "Otherwise, just hit enter to continue" << endl;
        cin.get();
        cout << "Very good! Now let's get started." << endl;
        cin.get();
        cout << "First things first, you have to choose your character." << endl;
        cin.get();
        cout << "Each has different attributes and you will be this character for the rest of\n"
             << "the game. So choose wisely." << endl;
        cin.get();
        //list character types
        cout << "WARRIOR:" << endl;
        cout << "The warrior is a physical fighter. His stats allow you to have extra max health \n"
             << "than the other characters." << endl;
        cout << "He has the lowest chance to miss, but also a lower critical hit rate." << endl;
        cin.get();
        cout << "WIZARD:" << endl;
        cout << "The wizard attacks using spells. His arsenal also allows the player to heal \n"
             << "themselves during battle." << endl;
        cout << "He has the highest chance to miss, but also has the highest critical hit rate." << endl;
        cin.get();
        cout << "LOOTER:" << endl;
        cout << "The looter is a physical fighter. His abilities allow you more gold and a much \n"
             << "better chance of loot per battle." << endl;
        cout << "He has an equal miss and critical hit rate." << endl;
        cin.get();
        printLine();
        cout << "\t      \"warrior\"             \"wizard\"             \"looter\"" << endl;
        printLine();
        cout << endl;
        //character selection
        do{
            cout << "Choose your character: ";
            getline(cin, characterType);
            cout << endl;

            if(characterType == "warrior"){
                // Warrior myWarrior(name, characterType);
                // character = &myWarrior;
                character = new Warrior(name, characterType);
            }
            else if(characterType == "wizard"){
                // Wizard myWizard(name, characterType);
                // character = &myWizard;
                character = new Wizard(name, characterType);
            }
            else if(characterType == "looter"){
                // Looter myLooter(name, characterType);
                // character = &myLooter;
                character = new Looter(name, characterType);
            }
            else{
                error();
                continue;
            }

            character->printStats();
            //confirm character selection
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

        //new game begins
        cout << "Let your journey begin!" << endl << endl;
        village.intro();
    }
    //sets initial village locations
    village.setLocations();
    //sets all shop items
    shop.setShop();
    //Runs as long as the game is on
    do{
        quit = false;
        //Output players banner
        for (string::size_type i=0; i < (80 - character->getName().length())/2; ++i)
            cout << " ";
        for (string::size_type i=0; i < character->getName().length(); ++i)
            cout << toupper(character->getName()[i],loc);
        cout << endl;
        village.updateLocations(character->getLevel());
        character->printStats();

        //Outputs village locations
        village.printLocations();
        //Gets users location choice
        choice = village.selection(character->getName());
        //Sends user home
        if(choice == "home"){
            home.intro(character);
        }
        //User starts on the path
        else if(choice == "path"){
            path.firstLocation(character);
        }
        //Opens users inventory
        else if(choice == "inventory"){
            character->inventory();
        }
        //User enters the shop
        else if(choice == "shop"){
            shop.shop(character);
        }
        //User travels to the river
        else if(choice == "river"){
            riverScene(character, firstPass, won);
        }
        //User travels to the forest
        else if(choice == "forest"){
            forestScene(character, won);
        }
        //User travels to the cliff
        else if(choice == "cliff"){
            cliffScene(character, won);
        }
        //User travels to the mountain
        else if(choice == "mountain"){
            mountainScene(character, won);
        }
        //Saves the users stats
        else if(choice == "save"){
            cout << "Are you sure you would like to save? This will overwrite any saved data.\n"
                 << "\"yes\" or \"no\"" << endl << endl;
            cout << character->getName() << ": ";
            getline(cin, choice);
            if(choice == "yes"){
                cout << "\nSaving, please wait..." << endl;
                this_thread::sleep_for (std::chrono::seconds(2));
                character->saveState(SAVES);
                cout << "Game saved. press enter to continue." << endl;
                cin.get();
            }
            else if(choice == "no"){
                continue;
            }
        }
        //Ends the program
        else if(choice == "quit"){
            cout << "Are you sure you would like to quit? All unsaved progress will be lost.\n"
                 << "\"yes\" or \"no\"" << endl << endl;
            cout << character->getName() << ": ";
            getline(cin, choice);
            cout << endl;
            if(choice == "yes"){
                quit = true;
            }
            else if(choice == "no"){
                continue;
            }
            else{
                error();
            }
        }
        //Error
        else{
            cout << "Input Error!" << endl;
            exit(0);
        }
    }while(!quit);
}

/**
 * Prints the introduction to Game Of Legends banner.
 */
void printBanner(){
    printLine();
    cout << "\t\t\t\tGAME OF LEGENDS" << endl;
    cout << "\t\t\t\t     -----" << endl;
    cout << "\t\t\t\tLand of Lerocia" << endl;
    printLine();
}

/**
 * Outputs an error for incorrect choice.
 */
void error()
{
    cout << "I'm sorry, that isn't an option." << endl << endl;
}

/**
 * Prints a line of 80 equals signs to cover a standard command line window.
 */
void printLine()
{
    for(int i = 0; i < 80; i++){
        cout << '=';
    }
    cout << endl;
}

/**
 * Runs the river location scene.
 *
 * @param character   The character class that the user chose.
 * @param firstPass   Checks if it is the first battle for the user.
 * @param won         Checks if the user has won the battle.
 */
void riverScene(Character *character, bool &firstPass, bool won){
    cout << "You wander out to the river right outside the village, as you get to the water\n"
         << "you begin to hear strange noises." << endl << endl;
    cout << "Watch out!" << endl;
    cout << "Press enter to fight." << endl;
    cin.get();
    int enemySelection = rand() % 2;
    Enemy *enemy;
    Battle battle;
    if(enemySelection == 0){
        if(character->getLevel() > 11){
            Tank tank("tank", 11);
            enemy = &tank;
        }
        else{
            do{
                Tank tank("tank", character->getLevel() + (rand()%3-1));
                enemy = &tank;
            }while(enemy->getLevel() == 0);
        }
    }
    else if(enemySelection == 1){
        if(character->getLevel() > 11){
            Beast beast("beast", 11);
            enemy = &beast;
        }
        else{
            do{
                Beast beast("beast", character->getLevel() + (rand()%3-1));
                enemy = &beast;
            }while(enemy->getLevel() == 0);
        }
    }
    else
        cout << "Selection Error!" << endl;
    if(firstPass){
        battle.intro(character, enemy, won);
        firstPass = false;
    }
    else
        battle.screen(character, enemy, won);
}

/**
 * Runs the forest location scene.
 *
 * @param character   The character class that the user chose.
 * @param won         Checks if the user has won the battle.
 */
void forestScene(Character *character, bool won){
    cout << "I guess you're more comfortable with leaving the village now, the forest is\n"
         << "seeming a little ominous." << endl << endl;
    cout << "What's that sound??" << endl;
    cout << "Press enter to fight." << endl;
    cin.get();
    int enemySelection = rand() % 2;
    Enemy *enemy;
    Battle battle;
    if(enemySelection == 0){
        if(character->getLevel() > 16){
            Brute brute("brute", 16);
            enemy = &brute;
        }
        else{
            Brute brute("brute", character->getLevel() + (rand()%3-1));
            enemy = &brute;
        }
    }
    else if(enemySelection == 1){
        if(character->getLevel() > 16){
            Wolf wolf("wolf", 16);
            enemy = &wolf;
        }
        else{
            Wolf wolf("wolf", character->getLevel() + (rand()%3-1));
            enemy = &wolf;
        }
    }
    else
        cout << "Selection Error!" << endl;
    battle.screen(character, enemy, won);
}

/**
 * Runs the cliff location scene.
 *
 * @param character   The character class that the user chose.
 * @param won         Checks if the user has won the battle.
 */
void cliffScene(Character *character, bool won){
    cout << "A little ways south of the village, you've heard rumors of the haunted cliff." << endl << endl;
    cout << "Looks like the rumors may be true!" << endl;
    cout << "Press enter to fight." << endl;
    cin.get();
    int enemySelection = rand() % 2;
    Enemy *enemy;
    Battle battle;
    if(enemySelection == 0){
        if(character->getLevel() > 21){
            Witch witch("witch", 21);
            enemy = &witch;
        }
        else{
            Witch witch("witch", character->getLevel() + (rand()%3-1));
            enemy = &witch;
        }
    }
    else if(enemySelection == 1){
        if(character->getLevel() > 21){
            Ghost ghost("ghost", 21);
            enemy = &ghost;
        }
        else{
            Ghost ghost("ghost", character->getLevel() + (rand()%3-1));
            enemy = &ghost;
        }
    }
    else
        cout << "Selection Error!" << endl;
    battle.screen(character, enemy, won);
}

/**
 * Runs the mountain location scene.
 *
 * @param character   The character class that the user chose.
 * @param won         Checks if the user has won the battle.
 */
void mountainScene(Character *character, bool won){
    cout << "You've trained long and hard, you're strong enough to make the climb." << endl << endl;
    cout << "But what lies at the peak??" << endl;
    cout << "Press enter to fight." << endl;
    cin.get();
    int enemySelection = rand() % 6;
    Enemy *enemy;
    Battle battle;
    if(enemySelection == 0){
        Tank tank("tank", character->getLevel() + (rand()%3-1));
        enemy = &tank;
    }
    else if(enemySelection == 1){
        Beast beast("beast", character->getLevel() + (rand()%3-1));
        enemy = &beast;
    }
    else if(enemySelection == 2){
        Brute brute("brute", character->getLevel() + (rand()%3-1));
        enemy = &brute;
    }
    else if(enemySelection == 3){
        Wolf wolf("wolf", character->getLevel() + (rand()%3-1));
        enemy = &wolf;
    }
    else if(enemySelection == 4){
        Witch witch("witch", character->getLevel() + (rand()%3-1));
        enemy = &witch;
    }
    else if(enemySelection == 5){
        Ghost ghost("ghost", character->getLevel() + (rand()%3-1));
        enemy = &ghost;
    }
    else
        cout << "Selection Error!" << endl;
    battle.screen(character, enemy, won);
}