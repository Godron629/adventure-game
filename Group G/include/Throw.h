#ifndef THROW_H
#define THROW_H

#include <Action.h>
#include <string>

class Throw : public Action
{
    public:
        Throw();
        virtual ~Throw();

    protected:

    private:
        std::string GetDescription();
        bool PerformAction();
};

#endif // THROW_H
