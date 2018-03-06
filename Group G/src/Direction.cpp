#include "Direction.h"
#include "Option.h"
#include <string>
#include <iostream>
using namespace std;

Direction::Direction()
{
    //ctor
}

Direction::~Direction()
{
    //dtor
}

East::East()
{
    //ctor
    description = "east";
    object = "East";
}

East::~East()
{
    //dtor
}
string East::GetDescription()
{
    return description;
}
void East::GetObject()
{
    cout<<object<<endl<<endl;
}

North::North()
{
    //ctor
    description = "north";
    object = "North";
}

North::~North()
{
    //dtor
}
string North::GetDescription()
{
    return description;
}
void North::GetObject()
{
    cout<<object<<endl<<endl;
}

South::South()
{
    //ctor
    description = "south";
    object = "South";
}

South::~South()
{
    //dtor
}
string South::GetDescription()
{
    return description;
}
void South::GetObject()
{
    cout<<object<<endl<<endl;
}

West::West()
{
    //ctor
    description = "west";
    object = "West";
}

West::~West()
{
    //dtor
}
string West::GetDescription()
{
    return description;
}
void West::GetObject()
{
    cout<<object<<endl<<endl;
}
