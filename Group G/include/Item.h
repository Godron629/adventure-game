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
        std::string object;
        virtual std::string GetDescription()=0;
        virtual void GetObject()=0;
    protected:

    private:

};

#endif // ITEM_H
