// ifndef checks if the identifier MONSTER_ROOM_H has not been defined yet
#ifndef MONSTER_ROOM_H
// ifndef block starts here

// define the identifier MONSTER_ROOM_H to prevent double inclusion of the header file
#define MONSTER_ROOM_H

// include necessary header
#include "Room.h"  // include Room header

// Forward declaration of Monster class
class Monster;

// MonsterRoom class declaration, derived from Room class
class MonsterRoom : public Room {
private:
    // private member variable to store pointer to Monster object
    Monster* monster;

public:
    // public constructor
    MonsterRoom();

    // overridden method to display room information
    void displayRoomInfo() override;

    // Getter method to access monster member variable
    Monster* getMonster() const;

    // Setter method to set monster member variable
    void setMonster(Monster* m);

    // Destructor
    ~MonsterRoom();
};

// endif closes the ifndef block
#endif // MONSTER_ROOM_H
// comment indicating the end of the ifndef block
