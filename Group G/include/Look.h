#ifndef LOOK_H
#define LOOK_H

#include <Action.h>
#include <string>

class Look : public Action
{
    public:
        Look();
        virtual ~Look();

    protected:

    private:
        std::string GetDescription();
        bool PerformAction();
};

#endif // LOOK_H
