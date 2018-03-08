#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <map>
#include <vector>
#include <exception>

class Room {
    public:
        Room(
            int id,
            std::string name,
            std::string description,
            std::map<std::string, int> neighbours,
            std::vector<std::string> npcs,
            std::vector<std::string> items
        );
        virtual ~Room();
        int getId();
        std::string getName();
        std::string getDescription();
        std::vector<std::string> getNpcs();
        std::vector<std::string> getItems();

    protected:

    private:
        int m_id;
        std::string m_name;
        std::string m_description;
        std::map<std::string, int> m_neighbours;
        std::vector<std::string> m_npcs;
        std::vector<std::string> m_items;

        int getNeighbourId(std::string direction);

};

#endif // ROOM_H
