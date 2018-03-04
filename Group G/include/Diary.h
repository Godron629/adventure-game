#ifndef DIARY_H
#define DIARY_H

#include <Book.h>
#include <string>

class Diary : public Book
{
    public:
        Diary();
        virtual ~Diary();
        void AddEntry(std::string);
    protected:

    private:
        virtual std::string GetDescription();
        virtual void GetObject();
        virtual std::vector<std::string> GetEntries();
};

#endif // DIARY_H
