#ifndef DIRECTION_H
#define DIRECTION_H

#include <Option.h>
#include <string>

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

#endif // DIRECTION_H
