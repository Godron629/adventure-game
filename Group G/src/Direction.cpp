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
    cardinal = "E";
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
string East::GetCardinal()
{
    return cardinal;
}

North::North()
{
    //ctor
    description = "north";
    object = "North";
    cardinal = "N";
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
string North::GetCardinal()
{
    return cardinal;
}
South::South()
{
    //ctor
    description = "south";
    object = "South";
    cardinal = "S";
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
string South::GetCardinal()
{
    return cardinal;
}
West::West()
{
    //ctor
    description = "west";
    object = "West";
    cardinal = "W";
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
string West::GetCardinal()
{
    return cardinal;
}
