#ifndef ACTION_H
#define ACTION_H
#include <string>

class Action
{
    public:
        Action();
        virtual ~Action();
        std::string description;
        std::string action;
        virtual std::string GetDescription()=0;
        virtual bool PerformAction()=0;
    protected:

    private:

};

#endif // ACTION_H
