// Include necessary headers
#include "Room.h"
#include <iostream>

// Constructor for Room class
Room::Room(std::string t) : type(t), connectedRooms{ nullptr, nullptr, nullptr, nullptr } {}

// Getter method for the room type
std::string Room::getType() const {
    return type;
}

// Getter method for the array of connected rooms
Room** Room::getConnectedRooms() {
    return connectedRooms;
}

// Method to add a connection to another room in a specific direction
void Room::addConnection(Room* room, Direction direction) {
    switch (direction) {
    case North:
        connectedRooms[0] = room;
        break;
    case West:
        connectedRooms[1] = room;
        break;
    case East:
        connectedRooms[2] = room;
        break;
    case South:
        connectedRooms[3] = room;
        break;
    }
}

// Method to display basic information about the room
void Room::displayRoomInfo() {
    std::cout << "Room Type: " << getType() << std::endl;
}

// Setter method for the room type
void Room::setType(std::string t) {
    type = t;
}

// Setter method to set a connected room in a specific direction
void Room::setConnectedRoom(Room* room, Direction direction) {
    connectedRooms[direction] = room;
}

// Destructor for Room class
Room::~Room() {
    // Destructor implementation
    // Delete dynamically allocated connected rooms

    for (int i = 0; i < 4; ++i) {
        delete connectedRooms[i];
    }
}
