#include "../include/Console.h"
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;
Console::Console()
{
    _flag = false;
    _input = "";
    _command = "";

    //ctor
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

    if(find(Commands.begin(), Commands.end(), first) != Commands.end())
    {
        if(find(Directions.begin(), Directions.end(), second) != Directions.end() || find(Objects.begin(), Objects.end(),second) != Objects.end())
        {
            if(first == "move")
                Move(second);
            else if(first == "grab")
                Grab(second);
            else if(first == "read")
                Read(second);
            else if(first == "look")
                Look(second);
            else if(first == "throw")
                Throw(second);
        }
        else if(first == "help")
            Help();
        else if(first == "quit")
            Quit();
        else
            cout << "Check your second argument..." << endl << endl;
    }
    else
        cout << "Type 'help' for help" << endl << endl;

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
void Console::Move(string dir)
{
    cout << "Moving "<< dir <<endl <<endl;
}
void Console::Grab(string obj)
{
    cout << "Grabbing " << obj << endl << endl;
}
void Console::Read(string obj)
{
    cout << "Reading " << obj << endl << endl;
}
void Console::Look(string dir)
{
    cout << "Looking " << dir << endl << endl;
}
void Console::Throw(string obj)
{
    cout << "Throwing out " << obj << endl << endl;
}

void Console::Help()
{
    for(auto i: Commands)
        cout << i << " | ";
    cout << endl << endl;
}
void Console::Quit()
{
    _flag = true;
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
    //dtor
}
