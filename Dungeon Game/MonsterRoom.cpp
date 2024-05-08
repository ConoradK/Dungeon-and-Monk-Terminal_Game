// Include necessary headers
#include "MonsterRoom.h"
#include "Monster.h"
#include "RandomUtils.h"  // Include the RandomUtils header
#include <iostream>

// Constructor for MonsterRoom class
MonsterRoom::MonsterRoom() : Room("MonsterRoom"), monster(nullptr) {
    // Randomly select a monster type using getRandomValue
    int typeIndex = getRandomValue(0, 2);

    // Create a monster based on the selected type
    switch (typeIndex) {
    case 0:
        monster = new Monster("Goblin", "A mischievous goblin", 10, 2);
        break;
    case 1:
        monster = new Monster("Orc", "A mighty Orc", 20, 3);
        break;
    case 2:
        monster = new Monster("Mind Slug", "Mind Controller", 4, 6);
        break;
    }
}

// Method to display room information
void MonsterRoom::displayRoomInfo() {
    // This method can be implemented to display specific information about the MonsterRoom
    // For example, it can display the type of monster present in the room
    if (monster != nullptr) {
        std::cout << "This room contains a " << monster->getName() << ".\n";
    }
    else {
        std::cout << "This room does not contain a monster.\n";
    }
}

// Getter method for the monster in the MonsterRoom
Monster* MonsterRoom::getMonster() const {
    return monster;
}

// Setter method for the monster in the MonsterRoom
void MonsterRoom::setMonster(Monster* m) {
    monster = m;
}

// Destructor for MonsterRoom class
MonsterRoom::~MonsterRoom() {
    // Destructor implementation
    // Delete the dynamically allocated Monster object
    delete monster;
}
