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
string East::GetObject()
{
    return object;
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
string North::GetObject()
{
    return object;
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
string South::GetObject()
{
    return object;
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
string West::GetObject()
{
    return object;
}
string West::GetCardinal()
{
    return cardinal;
}
