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
void Console::Prompt()
{
    cout << "> ";
}
void Console::ParseCommand()
{
    getline(cin, _input);
    cout << endl << endl;

    string first, second;

    first = GetFirst(_input);
    second = GetSecond(_input);

    first = ConvertStringToLower(first);
    second = ConvertStringToLower(second);

    Action* currentAction = nullptr;
    Option* currentOption = nullptr;

    for(auto i: Actions)
        if(i->GetDescription() == first)
           currentAction = i;

    if(second != "")
        for(auto i: Options)
            if(i->GetDescription() == second)
                currentOption = i;

    if(currentAction == 0 || (currentOption == 0 && currentAction->GetType() != Sys))
        ErrorMessage();
    else
    {
        switch (currentAction->GetType())
        {
            case Dir:
                if(dynamic_cast<Item*>(currentOption) == nullptr)
                    currentAction->PerformAction((Direction*)currentOption, _gameMap);
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
void Console::ErrorMessage()
{
    cout<<"Type 'help' for help"<<endl <<endl;
}
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
string Console::GetFirst(string input)
{
    char space = ' ';
    string first = "";

    first = input.substr(0, input.find(space));

    return first;
}

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
}
