// Include necessary headers
#include "TreasureRoom.h"
#include <iostream>

// Constructor for TreasureRoom class
TreasureRoom::TreasureRoom() : Room("TreasureRoom") {}

// Method to display specific information about the treasure room
void TreasureRoom::displayRoomInfo() {
    std::cout << "Room Type: Treasure" << std::endl;
}

// Destructor for TreasureRoom class
TreasureRoom::~TreasureRoom() {
    // Destructor implementation
    // Currently empty because there are no dynamically allocated resources to delete
}
