// ifndef checks if the identifier EMPTYROOM_H has not been defined yet
#ifndef EMPTYROOM_H
// ifndef block starts here

// define the identifier EMPTYROOM_H to prevent double inclusion of the header file
#define EMPTYROOM_H

// include the base Room header
#include "Room.h"

// EmptyRoom class declaration, derived from Room class
class EmptyRoom : public Room {

public:
    // public default constructor
    EmptyRoom();

    // overridden method to display room information
    void displayRoomInfo() override;

};

// endif closes the ifndef block
#endif // EMPTYROOM_H
// comment indicating the end of the ifndef block
