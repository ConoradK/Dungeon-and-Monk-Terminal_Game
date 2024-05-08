// include necessary header
#include "EmptyRoom.h"  // include EmptyRoom header
#include <iostream>     // for std::cout, std::endl

// EmptyRoom constructor
EmptyRoom::EmptyRoom()
    : Room("EmptyRoom") {}  // initialize base class Room with "EmptyRoom" type

// Display room information for EmptyRoom
void EmptyRoom::displayRoomInfo() {
    std::cout << "Room Type: Empty" << std::endl;  // print room type
}
