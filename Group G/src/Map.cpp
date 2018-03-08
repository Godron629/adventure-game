#include "Map.h"

using std::cout;
using std::string;
using std::vector;

Map::Map() {}

Map::~Map() {}

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
    int neighbourId = m_currentRoom->getNeighbourId(direction);
    if (neighbourId == -1) {
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
Room* Map::searchMapForRoom(int roomId) {
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

    vector<Room*> rooms;
    vector<string> items;
    vector<string> npcs;
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
        int id = -1;
        string element = "";
        string name = "";
        string description = "";
        npcs.clear();
        items.clear();
        neighbours.clear();

        // Iterate over elements of a single XML Room element
        for (rapidxml::xml_node<> * name_node = room_node->first_node("Id");
         name_node;
         name_node = name_node->next_sibling()) {
            // Collect information and make Room Object
            element = name_node->name();
            if (element == "Id") id = atoi(name_node->value());
            if (element == "Name") name = name_node->value();
            if (element == "Description") description = name_node->value();
            if (element == "Items") items.push_back(name_node->value());
            if (element == "Npcs") npcs.push_back(name_node->value());
            if (element == "N" || element == "E" || element == "S" || element == "W") neighbours[element] = atoi(name_node->value());
        }
        m_listOfRooms.push_back(new Room(id, name, description, neighbours, npcs, items));
	}
    m_currentRoom = rooms[0];
}
