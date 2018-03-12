#include "Map.h"

#include <iostream>
#include <exception>
#include <cstring>
#include "Item.h"
#include "rapidxml_utils.hpp"

using std::cout;
using std::string;
using std::vector;
using std::map;

Map::Map() {}

Map::~Map() {
    for (auto i: m_listOfRooms) {
        delete i;
    }
}

/**
@brief Returns a pointer to the current room of the player
*/
Room* Map::getCurrentRoom() {
    return m_currentRoom;
}

/**
@brief If there is a room in direction relative to currentRoom, make that the current room.
@param[in] direction Cardinal direction (N, E, S, W)
*/
void Map::changeCurrentRoom(string direction) {
    string neighbourId = m_currentRoom->getNeighbourId(direction);
    if (neighbourId == "-1") {
        cout << "You can't go that way.\n\n";
        return;
    }
    m_currentRoom = searchMapForRoom(neighbourId);
    cout << "Moving to: " << m_currentRoom->getName() << "\n\n";
    return;
}

/**
@brief Iterate listOfRooms searching for a room Id - return a pointer to found room.
@param[in] roomId Id of the room you want to search for.
@note should never return nullptr as each room needs an Id to be added to listOfRooms
*/
Room* Map::searchMapForRoom(string roomId) {
    for (Room* i: m_listOfRooms) {
        if (i->getId() == roomId) {
            return i;
        }
    }
    return nullptr;
}

/**
@brief Parse a game rooms XML file and create a list of pointers to each Room object
@param[in] filepath path of the XML file
@throws invalid_argument
*/
void Map::generateMapFromXml(string filepath) {
    const char* c_filepath = filepath.c_str();

    // Check if the file path exists
    std::ifstream pathExists(c_filepath);
    if (!pathExists) {
        throw std::invalid_argument("Invalid filepath");
    }

    tItemList items;
    tNpcList npcs;
    tNeighbours neighbours;

	rapidxml::xml_node<> * rootNode;
    rapidxml::file<> xmlFile(c_filepath);
    rapidxml::xml_document<> doc;

	doc.parse<0>(xmlFile.data());

	rootNode = doc.first_node("Rooms");

    // Iterate over XML Rooms elements
    for (rapidxml::xml_node<> * room_node = rootNode->first_node("Room");
     room_node;
     room_node = room_node->next_sibling()) {

        // Clear information gathered from previous Room
        string id = "", elementName = "", elementValue = "", name = "", description = "";
        npcs.clear();
        items.clear();
        neighbours.clear();

        // Iterate over elements of a single XML Room element
        for (rapidxml::xml_node<>* name_node = room_node->first_node("Id");
         name_node;
         name_node = name_node->next_sibling()) {

            // Convert node text from char* to string
            elementName = name_node->name();
            elementValue = name_node->value();

            // Collect information and make Room Object
            if (elementName == "Id") id = elementValue;
            if (elementName == "Name") name = elementValue;
            if (elementName == "Description") description = elementValue;
            if (elementName == "Items") collectItemsForRoom(elementValue, &items);
            if (elementName == "Npcs") npcs.push_back(elementValue); // TODO: Change this when NPCs implemented
            if (elementName == "N" || elementName == "E" ||
                elementName == "S" || elementName == "W" ||
                elementName == "U" || elementName == "D") neighbours[elementName] = elementValue;
        }
        m_listOfRooms.push_back(new Room(id, name, description, neighbours, npcs, items));
	}
    m_currentRoom = m_listOfRooms[0];
}

/**
@brief Make an Item and add it to a list of Items based on parameter itemName
@param[in] itemName Lowercase name of the item (item must be implemented)
@param[out] items List of Item pointers
@note This isn't the greatest solution as it requires an intimate knowledge of
 the item class. Also I don't think using pointers is necessary
*/
void Map::collectItemsForRoom(string itemName, tItemList *items) {
    if (itemName == "fish food") items->push_back(new FishFood());
    if (itemName == "gear") items->push_back(new Gear());
    if (itemName == "helmet") items->push_back(new Helmet());
    if (itemName == "key") items->push_back(new Key());
    if (itemName == "pile of bolts") items->push_back(new PileOfBolts());
    if (itemName == "rat poison") items->push_back(new RatPoison());
    if (itemName == "rubber tube") items->push_back(new RubberTube());
    if (itemName == "stick") items->push_back(new Stick());
    if (itemName == "quill") items->push_back(new Quill());
    if (itemName == "papyrus") items->push_back(new Papyrus());
}

