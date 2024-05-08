// ifndef checks if the identifier MONSTER_H has not been defined yet
#ifndef MONSTER_H
// ifndef block starts here

// define the identifier MONSTER_H to prevent double inclusion of the header file
#define MONSTER_H

// include necessary headers
#include "Fighter.h"  // include Fighter header

// Monster class declaration, derived from Fighter class
class Monster : public Fighter {
private:
    // Monster class does not introduce any new private attributes

public:
    // public constructor with parameters
    Monster(std::string n, std::string desc, int hp, int ap);

    // Override methods from the base Fighter class
    void attack(Fighter* target) override;  // overridden attack method
    void defend() override;                  // overridden defend method

    // Virtual destructor
    virtual ~Monster();
};

// endif closes the ifndef block
#endif // MONSTER_H
// comment indicating the end of the ifndef block
