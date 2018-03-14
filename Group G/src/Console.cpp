#include "../include/Console.h"
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Option.h"

using namespace std;

Console::Console(Inventory* inv, Map* gameMap)
{
    _flag = false;
    _input = "";
    _command = "";
    _inventory = inv;
    _gameMap = gameMap;
    Actions.insert(Actions.end(),new List(_inventory));
}
/**
 *\brief Prints ASCII Art to console.
 *\param[in] String filepath -> File path to file containing ASCIIART.
 */
void Console::PrintArt(string filepath)
{
    string art;
    ifstream infile;

    try
    {
        infile.open(filepath);
        if(!infile.is_open())
            throw invalid_argument("Invalid file path...");
        while(!infile.eof())
        {
            getline(infile, art);
            cout<<art<<endl;
        }

        infile.close();
    }
    catch(invalid_argument &e)
    {
        cerr<<e.what()<<endl;
    }
}
/**
 *\brief Prompts user input.
 */
void Console::Prompt()
{
    cout << "> ";
}
/**
 *\brief Parses user input and handles it.
 */
void Console::ParseCommand()
{
    //gets user input
    getline(cin, _input);
    cout << endl << endl;

    string first, second;

    //splits arguments
    first = GetFirst(_input);
    second = GetSecond(_input);

    first = ConvertStringToLower(first);
    second = ConvertStringToLower(second);

    Action* currentAction = nullptr;
    Option* currentOption = nullptr;
    Npc* currentNpc = nullptr;

    //finds action from first argument
    for(auto i: Actions)
        if(i->GetDescription() == first)
           currentAction = i;

    //Checks for a second argument
    if(second != "")
    {
        //If second argument is an option 'item, direction etc'
        for(auto i: Options)
            if(i->GetDescription() == second)
                currentOption = i;
        //If second argument is an NPC
        for(auto i: Npcs)
            if(i->getName() == second)
                currentNpc = i;
    }

    //Error Checking
    if(currentAction == 0 || (currentOption == 0 && currentAction->GetType() != Sys && currentAction->GetType() != Tlk))
        ErrorMessage();
    else
    {
        //Switch on Type of action and perform corresponding task.
        switch (currentAction->GetType())
        {
            case Dir:
                if(dynamic_cast<Item*>(currentOption) == nullptr)
                    currentAction->PerformAction((Direction*)currentOption, _gameMap);
                else
                    ErrorMessage();
                break;
            case Tlk:
                if(currentNpc != nullptr)
                    currentAction->PerformAction(_inventory, _gameMap, currentNpc);
                else
                    ErrorMessage();
                break;
            case Inv:
                if(dynamic_cast<Direction*>(currentOption) == nullptr)
                {
                    try
                    {
                        currentAction->PerformAction((Item*)currentOption,_inventory, _gameMap->getCurrentRoom());
                    }
                    catch(invalid_argument e)
                    {
                        cout<<e.what()<<endl<<endl;
                    }
                }
                else
                    ErrorMessage();
                break;
            case Sys:
                if(dynamic_cast<Look*>(currentAction) != nullptr)
                    currentAction->PerformAction(_gameMap->getCurrentRoom());
                else if(dynamic_cast<Type*>(currentAction) != nullptr)
                    currentAction->PerformAction(_inventory, _gameMap, second);
                else if(dynamic_cast<Crank*>(currentAction) != nullptr)
                    currentAction->PerformAction(_inventory, _gameMap);
                else if(dynamic_cast<Unlock*>(currentAction) != nullptr)
                    currentAction->PerformAction(_inventory, _gameMap);
                else
                {
                    Actions.insert(Actions.end(),new List(_inventory));
                    _flag = currentAction->PerformAction();
                }
                break;
            default:
                ErrorMessage();
        }
    }
}
/**
 *\brief Prints error message.
 */
void Console::ErrorMessage()
{
    cout<<"Type 'help' for help"<<endl <<endl;
}
/**
 *\brief Returns a string that has been converter to lowercase.
 *\param[in] String original -> string to convert.
 */
string Console::ConvertStringToLower(string original)
{
    for(unsigned int i = 0; i < original.length(); i++)
    {
        char temp = original[i];
        temp = tolower(temp);
        original[i] = temp;
    }
    return original;
}
/**
 *\brief Returns the second argument entered by the user.
 *\param[in] String input -> user input.
 */
string Console::GetSecond(string input)
{
    char space = ' ';
    string second = "";
    int start = -1;
    start = input.find(space);

    if(start != -1)
        second = input.substr(start + 1, input.length());

    return second;
}
/**
 *\brief Returns the first argument entered by the user.
 *\param[in] String input -> user input.
 */
string Console::GetFirst(string input)
{
    char space = ' ';
    string first = "";

    first = input.substr(0, input.find(space));

    return first;
}
/**
 *\brief Game loop while the quit flag is false.
 */
void Console::Run()
{
    while(!_flag)
    {
        Prompt();
        ParseCommand();
    }

}
Console::~Console()
{
    for (auto i: Options) {
        delete i;
    }

    for (auto i: Actions) {
        delete i;
    }

    for (auto i: Npcs)
        delete i;
}
