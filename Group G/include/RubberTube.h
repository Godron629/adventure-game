#ifndef RUBBERTUBE_H
#define RUBBERTUBE_H

#include <Item.h>
#include <string>

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

#endif // RUBBERTUBE_H
