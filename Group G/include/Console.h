#ifndef CONSOLE_H
#define CONSOLE_H
#include <string>
#include <list>
#include <vector>
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

        std::vector<std::string> Objects = {"thing1", "thing2"};
        std::vector<std::string> Directions = {"north", "east", "south", "west"};
        std::vector<std::string> Commands = {"move", "grab", "read", "look", "throw", "help", "quit"};
        void Move(std::string dir);
        void Grab(std::string obj);
        void Read(std::string obj);
        void Look(std::string dir);
        void Throw(std::string obj);
        void Help();
        void Quit();

    protected:

    private:
};

#endif // CONSOLE_H
