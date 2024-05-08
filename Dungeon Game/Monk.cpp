// Include necessary headers
#include "Monk.h"
#include "RandomUtils.h"  // Include the RandomUtils header
#include <iostream>

// Constructor for Monk class, initializing Fighter base class and current position
Monk::Monk(std::string n, std::string desc, int hp, int ap, Room* pos)
    : Fighter(n, desc, hp, ap), currentPosition(pos) {
}

// Method for Monk to attack a target
void Monk::attack(Fighter* target) {
    // Randomly determine if the attack hits or misses
    if (getRandomValue(0, 1) == 0) {
        // Reduce target's health points based on Monk's attack points
        target->setHealthPoints(target->getHealthPoints() - getAttackPoints());
        std::cout << "\n" << getName() << " attacked successfully\n" << std::endl;
    }
    else {
        std::cout << "\n" << getName() << " missed attack\n" << std::endl;
    }
}

// Method for Monk to defend
void Monk::defend() {
    // Randomly determine if the defense is successful or fails
    if (getRandomValue(0, 1) == 0) {
        // Increase Monk's health points by 1
        setHealthPoints(getHealthPoints() + 1);
        std::cout << "\n" << getName() << " Healed Successfully\n" << std::endl;
    }
    else {
        std::cout << "\n" << getName() << " Failed Healing\n" << std::endl;
    }
}

// Method for Monk to perform a healing prayer
void Monk::healingPrayer() {
    // Randomly determine if the healing prayer fully restores health or causes damage
    if (getRandomValue(0, 3) == 0) {
        // Fully restore Monk's health points
        setHealthPoints(getMaxHealthPoints());
        std::cout << "\nFully restored\n\n";
    }
    else {
        // Reduce Monk's health points by 3
        setHealthPoints(getHealthPoints() - 3);
        std::cout << "Damage 3 taken\n\n";
    }
}

// Getter method for Monk's current position
Room* Monk::getCurrentPosition() const {
    return currentPosition;
}

// Setter method for Monk's current position
void Monk::setCurrentPosition(Room* pos) {
    currentPosition = pos;
}

// Destructor for Monk class
Monk::~Monk() {
    // Virtual Destructor implementation
    // This is empty because Monk does not own any dynamically allocated resources
}
