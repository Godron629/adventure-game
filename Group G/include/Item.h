#ifndef ITEM_H
#define ITEM_H

#include <Option.h>
#include <string>

class Item : public Option
{
    public:
        Item();
        virtual ~Item();
        std::string description;
        virtual std::string GetDescription()=0;
        std::string object;
        virtual void GetObject()=0;
    protected:

    private:

};

#endif // ITEM_H
