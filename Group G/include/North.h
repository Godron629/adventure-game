#ifndef NORTH_H
#define NORTH_H

#include <Direction.h>
#include <string>

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

#endif // NORTH_H
