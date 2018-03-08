#ifndef MAP_H
#define MAP_H

#include "Room.h"

#include <string>
#include <vector>

class Map
{
    public:
        Map();
        virtual ~Map();
        void generateMapList(std::string filepath);
        bool changeCurrentRoom(std::string direction);
        Room* getCurrentRoom();

    protected:

    private:
        std::vector<Room*> listOfRooms;
        Room* m_currentRoom;
        Room* searchMapForRoom(int id);
};

#endif // MAP_H
