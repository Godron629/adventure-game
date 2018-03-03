#ifndef EAST_H
#define EAST_H

#include <Direction.h>
#include <string>

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

#endif // EAST_H
