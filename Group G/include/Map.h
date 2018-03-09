#ifndef MAP_H
#define MAP_H

#include "Room.h"
#include "rapidxml_utils.hpp"

#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <exception>
#include "Item.h"

class Map
{
    friend class Room;
    public:
        Map();
        virtual ~Map();

        Room* getCurrentRoom();
        void changeCurrentRoom(std::string direction);
        void generateMapFromXml(std::string filepath);

    protected:

    private:
        std::vector<Room*> m_listOfRooms;
        Room* m_currentRoom;
        Room* searchMapForRoom(std::string roomId);
        void collectItemsForRoom(std::string itemName, tItemList *items);
};

#endif // MAP_H
