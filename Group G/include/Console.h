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
        Console(Inventory*, Map*);
        virtual ~Console();
        std::string _input;
        std::string _command;
        Inventory* _inventory;
        Map* _gameMap;
        std::string GetFirst(std::string input);
        std::string GetSecond(std::string input);
        std::string ConvertStringToLower(std::string original);

        bool _flag;
        void PrintArt(std::string);
        void Prompt();
        void ParseCommand();
        void Run();
        void ErrorMessage();
        std::vector<Action*> Actions = {new Move(),new Drop(),new Grab(), new Look(), new Help(), new Quit(), new Type(), new Crank()};

        std::vector<Option*> Options = {new North(),new South(), new East(), new West(), new Up(), new Down(),
            new Key(), new Helmet(), new Stick(),new RubberTube(),new Gear(), new PileOfBolts(),
            new FishFood(), new RatPoison(), new Quill(), new Papyrus(), new Weight()};

    protected:

    private:
};

#endif // CONSOLE_H
