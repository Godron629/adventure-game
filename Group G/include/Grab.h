#ifndef GRAB_H
#define GRAB_H

#include <Action.h>
#include <string>

class Grab : public Action
{
    public:
        Grab();
        virtual ~Grab();

    protected:

    private:
        std::string GetDescription();
        bool PerformAction();
};

#endif // GRAB_H
