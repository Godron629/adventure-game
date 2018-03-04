#ifndef RATPOISON_H
#define RATPOISON_H

#include <Item.h>
#include <string>

class RatPoison : public Item
{
    public:
        RatPoison();
        virtual ~RatPoison();

    protected:

    private:
        virtual std::string GetDescription();
        virtual void GetObject();
};

#endif // RATPOISON_H
