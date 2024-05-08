// ifndef checks if the identifier TREASUREROOM_H has not been defined yet
#ifndef TREASUREROOM_H
// ifndef block starts here

// define the identifier TREASUREROOM_H to prevent double inclusion of the header file
#define TREASUREROOM_H

// include necessary header
#include "Room.h"  // include Room header

// TreasureRoom class declaration, derived from Room class
class TreasureRoom : public Room {
public:
    // public constructor
    TreasureRoom();

    // overridden method to display room information
    void displayRoomInfo() override;

    // overridden virtual destructor
    virtual ~TreasureRoom() override;
};

// endif closes the ifndef block
#endif // TREASUREROOM_H
// comment indicating the end of the ifndef block
