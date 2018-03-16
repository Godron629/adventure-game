#ifndef OPTION_H
#define OPTION_H
#include <string>

class Option
{
    public:
        Option() {};
        virtual ~Option() {};
        virtual std::string GetDescription()=0;
        virtual std::string GetObject()=0;
    protected:
        std::string description;
        std::string object;

    private:
};

#endif // OPTION_H
