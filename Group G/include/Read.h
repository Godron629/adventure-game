#ifndef READ_H
#define READ_H
#include "Book.h"
#include <Action.h>


class Read : public Action
{
    public:
        Read();
        virtual ~Read();

    protected:

    private:
        std::string GetDescription();
        ActionType GetType();
        bool PerformAction();
        void PerformAction(Book* book);
};

#endif // READ_H
