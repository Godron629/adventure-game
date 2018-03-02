#ifndef SOUTH_H
#define SOUTH_H

#include <Direction.h>
#include <string>

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

#endif // SOUTH_H
