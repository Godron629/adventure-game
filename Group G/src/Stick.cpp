#include "Stick.h"
#include <string>
#include <iostream>
using namespace std;
Stick::Stick()
{
    //ctor
    description = "stick";
    object = "Stick";
}

Stick::~Stick()
{
    //dtor
}
string Stick::GetDescription()
{
    return description;
}
void Stick::GetObject()
{
    cout<<object;
}
