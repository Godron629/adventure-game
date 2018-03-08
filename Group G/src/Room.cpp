#include "Room.h"

using std::string;

Room::Room(int id,
           string name,
           string description,
           tNeighbours neighbours,
           tList npcs,
           tList items) {
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
string Room::getName() {
    return m_name;
}

/**
@brief Return Room Description, such as 'It's a dark Room'
*/
string Room::getDescription() {
    return m_description;
}

/**
@brief Return the Id of the Room at direction - If there is no room, return -1.
@param[in] direction Uppercase cardinal direction (N, E, S, W)
@throws invalid_argument
*/
int Room::getNeighbourId(string direction) {
    if (direction == "N" || direction == "E" ||
        direction == "S" || direction == "W") {
        return m_neighbours[direction];
    }
    throw std::invalid_argument("Enter N, E, S, W");
}

/**
@brief Return list of npcs within the room
*/
tList Room::getNpcs() {
    return m_npcs;
}

/**
@brief Return list of items in the room
*/
tList Room::getItems() {
    return m_items;
}

