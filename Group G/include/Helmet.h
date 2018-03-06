#ifndef HELMET_H
#define HELMET_H

#include <Item.h>
#include <string>

class Helmet : public Item
{
    public:
        Helmet();
        virtual ~Helmet();

    protected:

    private:
        virtual std::string GetDescription();
        virtual void GetObject();
};

#endif // HELMET_H
