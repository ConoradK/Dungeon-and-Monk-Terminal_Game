// ifndef checks if the identifier MONK_H has not been defined yet
#ifndef MONK_H
// ifndef block starts here

// define the identifier MONK_H to prevent double inclusion of the header file
#define MONK_H

// include necessary headers
#include "Fighter.h"  // include Fighter header
#include "Room.h"     // include Room header
#include <vector>     // include vector header

// Monk class declaration, derived from Fighter class
class Monk : public Fighter {
private:
    // private member variable
    Room* currentPosition;  // pointer to the current position room

public:
    // public constructor with parameters and default argument
    Monk(std::string n, std::string desc, int hp, int ap, Room* pos = nullptr);

    // Additional method (commented out)
    //void visitRoom(Room* room);

    // Override methods from the base Fighter class
    void attack(Fighter* target) override;  // overridden attack method
    void defend() override;                  // overridden defend method

    // Getter and Setter methods for currentPosition
    Room* getCurrentPosition() const;  // getter method for currentPosition
    void setCurrentPosition(Room* pos); // setter method for currentPosition

    // Additional method specific to Monk class
    void healingPrayer();  // method to perform a healing prayer

    // Virtual destructor
    virtual ~Monk();
};

// endif closes the ifndef block
#endif // MONK_H
// comment indicating the end of the ifndef block
