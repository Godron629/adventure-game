#ifndef QUIT_H
#define QUIT_H

#include <Action.h>
#include <string>

class Quit : public Action
{
    public:
        Quit();
        virtual ~Quit();

    protected:

    private:
        std::string GetDescription();
        ActionType GetType();
        bool PerformAction();
};

#endif // QUIT_H
