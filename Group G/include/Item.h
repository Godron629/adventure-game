#ifndef ITEM_H
#define ITEM_H

#include <Option.h>
#include <string>
#include <vector>
class Item : public Option
{
    public:
        Item();
        virtual ~Item();
        std::string description;
        std::string object;
        virtual std::string GetDescription()=0;
        virtual void GetObject()=0;
    protected:

    private:

};

class Book : public Item
{
    public:
        Book();
        virtual ~Book();
        std::string description;
        std::string object;
        std::vector<std::string> entries;
        virtual std::string GetDescription()=0;
        virtual void GetObject()=0;
        virtual std::vector<std::string> GetEntries()=0;

    protected:

    private:
};

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

class FishFood : public Item
{
    public:
        FishFood();
        virtual ~FishFood();

    protected:

    private:
        virtual std::string GetDescription();
        virtual void GetObject();
};

class Gear : public Item
{
    public:
        Gear();
        virtual ~Gear();

    protected:

    private:
        virtual std::string GetDescription();
        virtual void GetObject();
};

class Helmet : public Item
{
    public:
        Helmet();
        virtual ~Helmet();

    protected:

    private:
        virtual std::string GetDescription();
        virtual void GetObject();
};

class Key : public Item
{
    public:
        Key();
        virtual ~Key();
    protected:

    private:

        virtual std::string GetDescription();
        virtual void GetObject();
};

class PileOfBolts : public Item
{
    public:
        PileOfBolts();
        virtual ~PileOfBolts();

    protected:

    private:
        virtual std::string GetDescription();
        virtual void GetObject();
};


class RatPoison : public Item
{
    public:
        RatPoison();
        virtual ~RatPoison();

    protected:

    private:
        virtual std::string GetDescription();
        virtual void GetObject();
};


class RubberTube : public Item
{
    public:
        RubberTube();
        virtual ~RubberTube();

    protected:

    private:
        virtual std::string GetDescription();
        virtual void GetObject();
};


class Stick : public Item
{
    public:
        Stick();
        virtual ~Stick();

    protected:

    private:
        virtual std::string GetDescription();
        virtual void GetObject();
};
#endif // ITEM_H

