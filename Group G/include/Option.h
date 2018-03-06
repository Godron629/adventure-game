#ifndef OPTION_H
#define OPTION_H
#include <string>
#include <vector>

class Option
{
    public:
        Option();
        virtual ~Option();
        std::string description;
        virtual std::string GetDescription()=0;
        std::string object;
        virtual void GetObject()=0;
    protected:

    private:
};






#endif // OPTION_H


