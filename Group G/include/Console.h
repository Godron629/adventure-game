#ifndef CONSOLE_H
#define CONSOLE_H
#include <string>
#include <list>
#include <vector>
#include "Action.h"
#include "Move.h"
#include "Grab.h"
#include "Look.h"
#include "Read.h"
#include "Throw.h"
#include "Help.h"
#include "Quit.h"
#include "Option.h"
#include "Direction.h"
#include "Item.h"
#include "North.h"
#include "South.h"
#include "East.h"
#include "West.h"
#include "Key.h"

class Console
{
    public:
        Console();
        virtual ~Console();
        std::string _input;
        std::string _command;

        std::string GetFirst(std::string input);
        std::string GetSecond(std::string input);
        std::string ConvertStringToLower(std::string original);

        bool _flag;
        void Prompt();
        void ParseCommand();
        void Run();

        std::vector<Action*> Actions = {new Move(),new Grab(),new Read(),new Look(),new Throw(), new Help(), new Quit()};
        std::vector<Option*> Options = {new North(),new South(), new East(), new West(), new Key()};

    protected:

    private:
};

#endif // CONSOLE_H
