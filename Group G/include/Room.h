#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <map>
#include <vector>
#include <exception>
#include "Item.h"

typedef std::map<std::string, std::string> tNeighbours;
typedef std::vector<Item*> tItemList;
typedef std::vector<std::string> tNpcList;

class Room {
    friend class Map;
    public:
        Room(
            std::string id,
            std::string name,
            std::string description,
            tNeighbours neighbours,
            tNpcList npcs,
            tItemList items
        );
        virtual ~Room();
        std::string getId();
        std::string getName();
        std::string getDescription();
        tNpcList getNpcs();
        tItemList getItems();

    protected:
        std::string getNeighbourId(std::string direction);

    private:
        std::string m_id;
        std::string m_name;
        std::string m_description;
        tNeighbours m_neighbours;
        tNpcList m_npcs;
        tItemList m_items;
};

#endif // ROOM_H
