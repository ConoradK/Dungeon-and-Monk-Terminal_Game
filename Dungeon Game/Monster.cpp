// Include necessary headers
#include "Monster.h"
#include <iostream>
#include "RandomUtils.h"

// Constructor for Monster class, initializing Fighter base class
Monster::Monster(std::string n, std::string desc, int hp, int ap)
    : Fighter(n, desc, hp, ap) {
}

// Method for Monster to attack a target
void Monster::attack(Fighter* target) {
    // Randomly determine if the attack hits or misses
    if (getRandomValue(0, 1) == 0) {
        // Reduce target's health points based on Monster's attack points
        target->setHealthPoints(target->getHealthPoints() - getAttackPoints());
        std::cout << getName() << " attacked successfully\n" << std::endl;
    }
    else {
        std::cout << getName() << " missed attack\n" << std::endl;
    }
}

// Method for Monster to defend
void Monster::defend() {
    // Randomly determine if the defense is successful or fails
    if (getRandomValue(0, 1) == 0) {
        // Increase Monster's health points by 1
        setHealthPoints(getHealthPoints() + 1);
        std::cout << getName() << " Healed Successfully\n" << std::endl;
    }
    else {
        std::cout << getName() << " Failed Healing\n" << std::endl;
    }
}

// Destructor for Monster class
Monster::~Monster() {
    // Virtual Destructor implementation
    // This is empty because Monster does not own any dynamically allocated resources
}
