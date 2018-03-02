#ifndef READ_H
#define READ_H

#include <Action.h>


class Read : public Action
{
    public:
        Read();
        virtual ~Read();

    protected:

    private:
        std::string GetDescription();
        bool PerformAction();
};

#endif // READ_H
