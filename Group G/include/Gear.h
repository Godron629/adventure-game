#ifndef GEAR_H
#define GEAR_H

#include <Item.h>
#include <string>

class Gear : public Item
{
    public:
        Gear();
        virtual ~Gear();

    protected:

    private:
        virtual std::string GetDescription();
        virtual void GetObject();
};

#endif // GEAR_H
