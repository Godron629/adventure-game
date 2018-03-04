#include "../include/Console.h"
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include "Option.h"
using namespace std;
Console::Console(Inventory* inv)
{
    _flag = false;
    _input = "";
    _command = "";
    _inventory = inv;
    Actions.insert(Actions.end(),new List(_inventory));
    //ctor
}
void Console::ConsoleStart()
{
    cout << "\t\t\t\tWelcome to dis litttt ass game. Don't die and stuff."<<endl<<endl;
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

    bool contains = false;

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
                {
                    currentAction->PerformAction();
                    currentOption->GetObject();
                }
                else
                    ErrorMessage();
                break;
            case Inv:
                if(dynamic_cast<Direction*>(currentOption) == nullptr)
                {
                    try
                    {
                        currentAction->PerformAction((Item*)currentOption,_inventory);
                        currentOption->GetObject();
                        cout<<endl<<endl;
                    }
                    catch(invalid_argument e)
                    {
                        ErrorMessage();
                    }
                }
                else
                    ErrorMessage();
                break;
            case Sys:
                Actions.insert(Actions.end(),new List(_inventory));
                _flag = currentAction->PerformAction();
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
    for(int i = 0; i < original.length(); i++)
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
    ConsoleStart();
    while(!_flag)
    {
        Prompt();
        ParseCommand();
    }

}
Console::~Console()
{
    //dtor
}
