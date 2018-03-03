#ifndef MOVE_H
#define MOVE_H

#include <Action.h>
#include <string>

class Move : public Action
{
    public:
        Move();
        virtual ~Move();

    protected:

    private:
        std::string GetDescription();
        ActionType GetType();
        bool PerformAction();
};

#endif // MOVE_H
