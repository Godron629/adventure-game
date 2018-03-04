#ifndef BOOK_H
#define BOOK_H

#include <Item.h>
#include <string>
#include <vector>

class Book : public Item
{
    public:
        Book();
        virtual ~Book();
        std::string description;
        std::string object;
        std::vector<std::string> entries;
        virtual std::string GetDescription()=0;
        virtual void GetObject()=0;
        virtual std::vector<std::string> GetEntries()=0;

    protected:

    private:
};

#endif // BOOK_H
