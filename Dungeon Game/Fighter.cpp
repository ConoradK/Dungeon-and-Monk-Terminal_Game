// include necessary header
#include "Fighter.h"   // include Fighter header
#include <iostream>    // for std::cout, std::endl

// Fighter constructor
Fighter::Fighter(std::string n, std::string desc, int hp, int ap)
    : name(n), description(desc), healthPoints(hp), attackPoints(ap), maxHealthPoints(hp) {
    // Initialize Fighter object with provided values
}

// Setter method for healthPoints with boundary checks
void Fighter::setHealthPoints(int hp) {
    if (hp < 0) {
        healthPoints = 0;  // Set healthPoints to 0 if hp is negative
    }
    else if (hp > maxHealthPoints) {
        healthPoints = maxHealthPoints;  // Set healthPoints to maxHealthPoints if hp exceeds maxHealthPoints
    }
    else {
        healthPoints = hp;  // Set healthPoints to hp
    }
}

// Setter methods for name, attackPoints, and description
void Fighter::setName(std::string n) { name = n; }
void Fighter::setAttackPoints(int ap) { attackPoints = ap; }
void Fighter::setDescription(std::string desc) { description = desc; }  // Corrected assignment from name to description

// Attack method placeholder
void Fighter::attack(Fighter* target) {
    // Implementation to be defined
}

// Defend method placeholder
void Fighter::defend() {
    // Implementation to be defined
}

// Display Fighter information
void Fighter::displayInfo() {
    std::cout << "\t" << name << ": " << description << "\n";  // Print name and description
    std::cout << "\tStats:\n";
    std::cout << "\t\t" << "Attack Points: " << attackPoints << "\n";  // Print attackPoints
    std::cout << "\t\t" << "Health Points: " << healthPoints << "\n";  // Print healthPoints
    std::cout << "\t\t" << "Max Health Points: " << maxHealthPoints << "\n\n\n\n";  // Print maxHealthPoints
}

// Virtual Destructor
Fighter::~Fighter() {
    // Virtual Destructor implementation
    // This is empty because Fighter does not own any dynamically allocated resources
}
