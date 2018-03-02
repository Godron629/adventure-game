#ifndef HELP_H
#define HELP_H

#include <Action.h>
#include <string>


class Help : public Action
{
    public:
        Help();
        virtual ~Help();

    protected:

    private:
        std::string GetDescription();
        bool PerformAction();
};

#endif // HELP_H
