#ifndef KEY_H
#define KEY_H

#include <Item.h>
#include <string>

class Key : public Item
{
    public:
        Key();
        virtual ~Key();
    protected:

    private:

        virtual std::string GetDescription();
        virtual void GetObject();
};

#endif // KEY_H
