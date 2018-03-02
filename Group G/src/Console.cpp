#include "../include/Console.h"
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include "Option.h"
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

    bool contains = false;



    for(auto i: Actions)
    {
        if(i->GetDescription() == first)
        {
            Option* tempOpt = nullptr;
            contains = true;
            if(second != "")
            {
                contains = false;
                for(auto j: Options)
                {
                    if(j->GetDescription() == second)
                    {
                        tempOpt = j;
                        contains = true;
                    }

                }
            }
            if(contains)
                _flag = i->PerformAction();
            if(tempOpt != 0)
                tempOpt->GetObject();
        }
    }

    (contains == false)?cout << "Type 'help' for help" << endl << endl:cout;

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
