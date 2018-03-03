#ifndef WEST_H
#define WEST_H

#include <Direction.h>
#include <string>

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

#endif // WEST_H
