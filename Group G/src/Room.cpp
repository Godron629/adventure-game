#include "Room.h"

#include <exception>

using std::string;

Room::Room(string id,
           string name,
           string description,
           tNeighbours neighbours,
           tNpcList npcs,
           tItemList items) {
    m_id = id;
    m_name = name;
    m_description = description;
    m_neighbours = neighbours;
    m_npcs = npcs;
    m_items = items;
}

Room::~Room(){
    for (auto i: m_items) {
        delete i;
    }
}

/**
@brief Returns Room Id. Each Room has a unique Id described in XML map file.
*/
string Room::getId() {
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
@param[in] direction Uppercase cardinal direction (N, E, S, W, U, D)
@throws invalid_argument
*/
string Room::getNeighbourId(string direction) {
    if (direction == "N" || direction == "E" ||
        direction == "S" || direction == "W" ||
        direction == "U" || direction == "D") {
        return m_neighbours[direction];
    }
    throw std::invalid_argument("Enter N, E, S, W, U, D");
}

/**
@brief Return list of npcs within the room
*/
tNpcList Room::getNpcs() {
    return m_npcs;
}

/**
@brief Return list of items in the room
*/
tItemList Room::getItems() {
    return m_items;
}
void Room::addItem(Item* item){
    m_items.push_back(item);
}
void Room::removeItem(Item* item){
    for(int i = 0; i < (int)m_items.size(); i++)
        if(m_items[i]->GetDescription() == item->GetDescription())
            m_items.erase(m_items.begin() + i);
}
