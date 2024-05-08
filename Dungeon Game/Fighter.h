// ifndef checks if the identifier FIGHTER_H has not been defined yet
#ifndef FIGHTER_H
// ifndef block starts here

// define the identifier FIGHTER_H to prevent double inclusion of the header file
#define FIGHTER_H

// include necessary headers
#include <string> // for std::string

// Fighter class declaration
class Fighter {
private:
    // private member variables
    std::string name;            // fighter's name
    std::string description;     // fighter's description
    int healthPoints;            // fighter's health points
    int attackPoints;            // fighter's attack points
    int maxHealthPoints;         // fighter's maximum health points

public:
    // public constructor with parameters
    Fighter(std::string name, std::string description, int hp, int ap);

    // Getter methods to access private member variables
    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    int getHealthPoints() const { return healthPoints; }
    int getAttackPoints() const { return attackPoints; }
    int getMaxHealthPoints() const { return maxHealthPoints; }

    // Setter methods to modify private member variables
    void setName(std::string name);
    void setHealthPoints(int hp);
    void setAttackPoints(int ap);
    void setDescription(std::string description);

    // Virtual methods to be overridden by derived classes
    virtual void attack(Fighter* target) = 0; // pure virtual method for attacking
    virtual void defend() = 0;                // pure virtual method for defending

    // Method to display fighter information
    void displayInfo();

    // Destructor
    virtual ~Fighter();
};

// endif closes the ifndef block
#endif // FIGHTER_H
// comment indicating the end of the ifndef block
