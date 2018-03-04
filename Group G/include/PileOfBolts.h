#ifndef PILEOFBOLTS_H
#define PILEOFBOLTS_H

#include <Item.h>
#include <string>

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

#endif // PILEOFBOLTS_H
