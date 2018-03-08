#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <map>
#include <vector>
#include <exception>

typedef std::map<std::string, int> tNeighbours;
typedef std::vector<std::string> tList;

class Room {
    friend class Map;
    public:
        Room(
            int id,
            std::string name,
            std::string description,
            tNeighbours neighbours,
            tList npcs,
            tList items
        );
        virtual ~Room();
        int getId();
        std::string getName();
        std::string getDescription();
        tList getNpcs();
        tList getItems();

    protected:
        int getNeighbourId(std::string direction);

    private:
        int m_id;
        std::string m_name;
        std::string m_description;
        tNeighbours m_neighbours;
        tList m_npcs;
        tList m_items;

};

#endif // ROOM_H
