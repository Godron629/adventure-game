#ifndef DIRECTION_H
#define DIRECTION_H

#include <string>
#include <vector>

#include "Option.h"
class Direction : public Option
{
    public:
        Direction() {};
        virtual ~Direction() {};
        std::string GetDescription();
        std::string GetObject();
        std::string GetCardinal();
    protected:
        std::string cardinal;
        std::string object;
        std::string description;
};

class East : public Direction
{
    public:
        East();
};

class North : public Direction
{
    public:
        North();
};

class South : public Direction
{
    public:
        South();
};

class West : public Direction
{
    public:
        West();
};

class Up : public Direction
{
    public:
        Up();
};

class Down : public Direction
{
    public:
        Down();
};
#endif // DIRECTION_H
