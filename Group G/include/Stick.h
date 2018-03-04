#ifndef STICK_H
#define STICK_H

#include <Item.h>
#include <string>

class Stick : public Item
{
    public:
        Stick();
        virtual ~Stick();

    protected:

    private:
        virtual std::string GetDescription();
        virtual void GetObject();
};

#endif // STICK_H
