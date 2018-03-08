#ifndef MAP_H
#define MAP_H

#include "Room.h"
#include "rapidxml_utils.hpp"

#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <exception>

class Map
{
    friend class Room;
    public:
        Map();
        virtual ~Map();

        void changeCurrentRoom(std::string direction);
        Room* getCurrentRoom();

    protected:

    private:
        std::vector<Room*> m_listOfRooms;
        Room* m_currentRoom;

        Room* searchMapForRoom(int roomId);
        void generateMapFromXml(std::string filepath);
};

#endif // MAP_H
