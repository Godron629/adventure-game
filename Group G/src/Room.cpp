#include "Room.h"

Room::Room(int id,
           std::string name,
           std::string description,
           std::map<std::string, int> neighbours,
           std::vector<std::string> npcs,
           std::vector<std::string> items) {
    m_id = id;
    m_name = name;
    m_description = description;
    m_neighbours = neighbours;
    m_npcs = npcs;
    m_items = items;
}

Room::~Room(){}

/**
@brief Returns Room Id. Each Room has a unique Id described in XML map file.
*/
int Room::getId() {
    return m_id;
}

/**
@brief Return Room Name, such as Crumbling Signpost or Bathroom.
*/
std::string Room::getName() {
    return m_name;
}

/**
Return Room Description, such as 'It's a dark Room'
*/
std::string Room::getDescription() {
    return m_description;
}

/**
Return the Id of the Room in some cardinal direction. If there is no room
in that direction, return -1.
@param[in] direction Uppercase cardinal direction (N, E, S, W)
@throws invalid_argument
*/
int Room::getNeighbourId(std::string direction) {
    if (direction == "N" || direction == "E" ||
        direction == "S" || direction == "W") {
        return m_neighbours[direction];
    }
    throw std::invalid_argument("Enter N, E, S, W");
}

/**
Return list of npcs within the room
*/
std::vector<std::string> Room::getNpcs() {
    return m_npcs;
}

/**
Return list of items in the room
*/
std::vector<std::string> Room::getItems() {
    return m_items;
}

