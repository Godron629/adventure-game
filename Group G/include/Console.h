#ifndef CONSOLE_H
#define CONSOLE_H
#include <string>
#include <list>
#include <vector>
#include "Action.h"
#include "Option.h"
#include "Direction.h"
#include "Item.h"
#include "Inventory.h"

class Console
{
    public:
        Console(Inventory*);
        virtual ~Console();
        std::string _input;
        std::string _command;
        Inventory* _inventory;
        std::string GetFirst(std::string input);
        std::string GetSecond(std::string input);
        std::string ConvertStringToLower(std::string original);

        bool _flag;
        void PrintArt(std::string);
        void Prompt();
        void ParseCommand();
        void Run();
        void ErrorMessage();
        std::vector<Action*> Actions = {new Move(),new Drop(),new Grab(), new Read(),new Look(), new Help(), new Quit()};

        std::vector<Option*> Options = {new North(),new South(), new East(), new West(), new Key(), new Helmet(), new Stick(),new RubberTube(),new Gear(), new PileOfBolts(), new FishFood(), new RatPoison()};

    protected:

    private:
};

#endif // CONSOLE_H
