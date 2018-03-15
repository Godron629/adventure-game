#include "..\include\Direction.h"

#include <string>

using std::string;

string Direction::GetDescription() {
    return description;
}
string Direction::GetObject() {
    return object;
}
string Direction::GetCardinal() {
    return cardinal;
}

East::East()
{
    description = "east";
    object = "East";
    cardinal = "E";
}

North::North()
{
    description = "north";
    object = "North";
    cardinal = "N";
}

South::South()
{
    description = "south";
    object = "South";
    cardinal = "S";
}

West::West()
{
    description = "west";
    object = "West";
    cardinal = "W";
}

Up::Up()
{
    description = "up";
    object = "Up";
    cardinal = "U";
}

Down::Down()
{
    description = "down";
    object = "Down";
    cardinal = "D";
}

