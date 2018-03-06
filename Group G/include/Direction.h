#ifndef DIRECTION_H
#define DIRECTION_H

#include <string>
#include <vector>

#include "Option.h"
class Direction : public Option
{
    public:
        Direction();
        virtual ~Direction();
        std::string description;
        virtual std::string GetDescription()=0;
        std::string object;
        virtual void GetObject()=0;
    protected:

    private:

};

class East : public Direction
{
    public:
        East();
        virtual ~East();

    protected:

    private:
        virtual std::string GetDescription();
        virtual void GetObject();
};

class North : public Direction
{
    public:
        North();
        virtual ~North();

    protected:

    private:
        virtual std::string GetDescription();
        virtual void GetObject();
};

class South : public Direction
{
    public:
        South();
        virtual ~South();

    protected:

    private:
        virtual std::string GetDescription();
        virtual void GetObject();
};

class West : public Direction
{
    public:
        West();
        virtual ~West();

    protected:

    private:
        virtual std::string GetDescription();
        virtual void GetObject();
};
#endif // DIRECTION_H
