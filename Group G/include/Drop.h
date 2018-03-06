#ifndef DROP_H
#define DROP_H

#include <Action.h>
#include <string>

class Drop : public Action
{
    public:
        Drop();
        virtual ~Drop();

    protected:

    private:
        ActionType GetType();
        std::string GetDescription();
        bool PerformAction();
        void PerformAction(Item*,Inventory*);
};

#endif // DROP_H
