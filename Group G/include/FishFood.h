#ifndef FISHFOOD_H
#define FISHFOOD_H

#include <Item.h>
#include <string>

class FishFood : public Item
{
    public:
        FishFood();
        virtual ~FishFood();

    protected:

    private:
        virtual std::string GetDescription();
        virtual void GetObject();
};

#endif // FISHFOOD_H
