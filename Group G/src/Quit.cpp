#include "Quit.h"
#include <string>
#include <iostream>
#include "Console.h"

using namespace std;
Quit::Quit()
{
    //ctor
    description = "quit";
    action = "Quitting...";
}

Quit::~Quit()
{
    //dtor
}
string Quit::GetDescription()
{
    return description;
}
bool Quit::PerformAction()
{
    cout<<action<<endl;
    return true;
}
