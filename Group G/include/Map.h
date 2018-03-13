#ifndef MAP_H
#define MAP_H

#include "Room.h"

#include <string>
#include <vector>


class Map
{
    friend class Room;
    public:
        Map();
        virtual ~Map();

        Room* getCurrentRoom();
        void sendToRoom(std::string roomId);
        void changeCurrentRoom(std::string direction);
        void generateMapFromXml(std::string filepath);

    protected:

    private:
        std::vector<Room*> m_listOfRooms;
        Room* m_currentRoom;
        Room* searchMapForRoom(std::string roomId);
        void collectItemsForRoom(std::string itemName, tItemList *items);
        void collectNpcsForRoom(std::string npcName, tNpcList *npcs);
};

#endif // MAP_H
