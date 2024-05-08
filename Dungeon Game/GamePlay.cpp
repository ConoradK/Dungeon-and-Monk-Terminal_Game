// include necessary headers
#include "Dungeon.h"
#include "Monk.h"
#include "Monster.h"
#include "MonsterRoom.h"
#include <iostream>
#include <string>
#include "RandomUtils.h"  // Include the RandomUtils header
#include "Direction.h"
#include "Difficulty.h"

// Function to handle room selection
void roomSelection(Monk& monk) {
    // Get connected rooms from current position
    Room** connected_rooms = monk.getCurrentPosition()->getConnectedRooms();

    std::string directionInput;
    double directionChoice;

    // Display directions for selection
    std::cout << "Choose a direction:" << std::endl;
    std::cout << "1: North" << std::endl;
    std::cout << "2: West" << std::endl;
    std::cout << "3: East" << std::endl;
    std::cout << "4: South" << std::endl;

    // Exception handling for invalid input
    while (true) {
        try {
            std::cin >> directionInput;

            // Check if input contains a decimal point or comma
            if (directionInput.find('.') != std::string::npos || directionInput.find(',') != std::string::npos) {
                throw std::invalid_argument("Invalid choice. Choose an integer between 1 to 4.");
            }

            directionChoice = std::stod(directionInput);

            if (directionChoice < 1 || directionChoice > 4 || directionChoice != static_cast<int>(directionChoice)) {
                throw std::invalid_argument("Invalid choice. Choose between 1 to 4.");
            }

            break;
        }
        catch (const std::exception& e) {
            std::cout << "\nInvalid choice. Choose an integer between 1 to 4.\n" << std::endl;
            std::cout << "Choose a direction:" << std::endl;
            std::cout << "1: North" << std::endl;
            std::cout << "2: West" << std::endl;
            std::cout << "3: East" << std::endl;
            std::cout << "4: South" << std::endl;
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard the input
        }
    }

    // Set the monk's current position to the selected room
    monk.setCurrentPosition(connected_rooms[static_cast<int>(directionChoice) - 1]);

    Dungeon* dungeon = Dungeon::getInstance();
    dungeon->updateVisited(monk.getCurrentPosition());
}

// Function to handle combat between monk and monster
bool combat(Monk* monk, Monster* monster) {
    monk->displayInfo();
    monster->displayInfo();

    while (true) {
        // Monk's turn
        int combatMove;

        std::cout << "Choose an action, " << monk->getName() << "\n (1: Attack, 2: Defend): ";

        // Exception handling for invalid input
        while (true) {
            try {
                std::string input;
                std::cin >> input;

                // Check if input contains a decimal point or comma
                if (input.find('.') != std::string::npos || input.find(',') != std::string::npos) {
                    throw std::invalid_argument("Invalid choice. Choose an integer between 1 to 2.");
                }

                combatMove = std::stoi(input);

                if (combatMove != 1 && combatMove != 2) {
                    throw std::invalid_argument("Invalid choice. Choose either 1 (Attack) or 2 (Defend).");
                }
                break;
            }
            catch (const std::exception& e) {
                std::cout << "\nInvalid choice. Choose either 1 (Attack) or 2 (Defend)." << std::endl;
                std::cout << "Choose an action, " << monk->getName() << " (1: Attack, 2: Defend): ";
                std::cin.clear();  // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard the input
            }
        }

        switch (combatMove) {
        case 1:
            monk->attack(monster);
            break;
        case 2:
            monk->defend();
            break;
        }

        monk->displayInfo();
        monster->displayInfo();

        // Check if monster is defeated
        if (monster->getHealthPoints() <= 0) {
            std::cout << monster->getName() << " has been defeated!" << std::endl;

            dynamic_cast<MonsterRoom*>(monk->getCurrentPosition())->setMonster(nullptr);
            (monk->getCurrentPosition())->setType("EmptyRoom");
            std::cout << "This Room has become an Empty Room!!\n" << std::endl;

            Dungeon* dungeon = Dungeon::getInstance();
            dungeon->displayDungeon(monk);

            return true;
        }

        std::cout << "monster's turn\n" << std::endl;
        // Monster's turn
        if (getRandomValue(0, 1) == 0) {
            monster->attack(monk);
        }
        else {
            monster->defend();
        }

        monk->displayInfo();
        monster->displayInfo();

        // Check if monk is defeated
        if (monk->getHealthPoints() <= 0) {
            std::cout << "GAME OVER\n";
            std::cout << monk->getName() << " has been defeated!" << std::endl;

            std::cout << "Here is the outline of the Dungeon" << std::endl;
            Dungeon* dungeon = Dungeon::getInstance();
            dungeon->displayDungeonAllCaps();

            return false;
        }
    }
}

// Main function
int main() {
    Dungeon* dungeon = Dungeon::getInstance();

    // Set dungeon difficulty and generate dungeon
    dungeon->setDifficulty(Medium);
    dungeon->generateDungeon();

    // Create monk character
    Monk* monk = new Monk("Conrad", "A brave cow boy monk", 15, 3, dungeon->getStartRoom());

    // Display dungeon statistics and initial dungeon layout
    dungeon->displayDungeonStats();
    dungeon->updateVisited(monk->getCurrentPosition());
    std::cout << std::endl;
    dungeon->displayDungeon(monk);
    std::cout << std::endl;

    // Game loop until treasure room is reached
    while (monk->getCurrentPosition() != dungeon->getTreasureRoomLocation()) {
        Room* currentRoom = monk->getCurrentPosition();

        std::cout << "You find Yourself inside the " << currentRoom->getType() << "!!\n\n\n";

        // Handle combat in monster room
        if (currentRoom->getType() == "MonsterRoom") {
            if (!combat(monk, (dynamic_cast<MonsterRoom*>(currentRoom))->getMonster())) {
                return 0;
            }
        }
        // Handle healing in empty room
        else if (currentRoom->getType() == "EmptyRoom") {
            char healingDecision;

            while (true) {
                std::cout << "Would you like to perform a healing prayer? (y/n): \n";
                try {
                    std::cin >> healingDecision;

                    if (std::cin.fail() || (tolower(healingDecision) != 'y' && tolower(healingDecision) != 'n')) {
                        throw std::invalid_argument("Invalid choice. Please choose (y/n) \n");
                    }
                    break;
                }
                catch (const std::exception& e) {
                    std::cout << e.what() << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }

            if (tolower(healingDecision) == 'y') {
                monk->healingPrayer();
                monk->displayInfo();
                if (monk->getHealthPoints() == 0) {
                    std::cout << "You lose" << std::endl;
                    return 0;
                }
            }
            else {
                std::cout << "\nSkipped weak healing\n\n";
            }
        }

        // Proceed to room selection
        roomSelection(*monk);
        dungeon->displayDungeon(monk);  // Display after room selection
    }

    std::cout << "\n\nYou Found the Treasure Room!!" << std::endl;
    std::cout << "You win!!" << std::endl;

    std::cout << "Here is the outline of the Dungeon" << std::endl;
    dungeon->displayDungeonAllCaps();

    return 0;
}
