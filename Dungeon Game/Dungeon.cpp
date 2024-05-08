// include necessary headers
#include <vector>          // for std::vector
#include <string>          // for std::string
#include <random>          // for random number generation
#include <algorithm>       // for std::shuffle
#include "Direction.h"     // include Direction header
#include "Room.h"          // include Room header
#include "Difficulty.h"    // include Difficulty header
#include "RandomUtils.h"   // include RandomUtils header
#include "TreasureRoom.h"  // include TreasureRoom header
#include "EmptyRoom.h"     // include EmptyRoom header
#include "MonsterRoom.h"   // include MonsterRoom header
#include "Dungeon.h"       // include Dungeon header
#include <iostream>        // for std::cout, std::endl
#include <iomanip>         // for std::setw

// initialize static instance pointer to nullptr
Dungeon* Dungeon::instance = nullptr;

// Get singleton instance of Dungeon
Dungeon* Dungeon::getInstance() {
    if (!instance) {
        instance = new Dungeon();
    }
    return instance;
}

// Dungeon constructor
Dungeon::Dungeon()
    : startRoom(nullptr), treasureRoomLocation(nullptr), numColumns(0), numRows(0), difficulty(Difficulty::Easy) {}

// Getter methods
const std::vector<Room*>& Dungeon::getRooms() const {
    return rooms;
}

Room* Dungeon::getStartRoom() {
    return startRoom;
}

Room* Dungeon::getTreasureRoomLocation() {
    return treasureRoomLocation;
}

Difficulty Dungeon::getDifficulty() {
    return difficulty;
}

// Setter methods
void Dungeon::setStartRoom(Room* room) {
    startRoom = room;
}

void Dungeon::setDifficulty(Difficulty set_difficulty) {
    difficulty = set_difficulty;
}

// Generate dungeon layout based on difficulty
void Dungeon::generateDungeon() {
    // Determine dungeon dimensions based on difficulty
    switch (difficulty) {
    case Difficulty::Easy:
        numRows = static_cast<int>(getRandomValue(0, 2)) + 2;
        numColumns = static_cast<int>(getRandomValue(0, 2)) + 2;
        break;
    case Difficulty::Medium:
        numRows = static_cast<int>(getRandomValue(2, 4)) + 2;
        numColumns = static_cast<int>(getRandomValue(2, 4)) + 2;
        break;
    case Difficulty::Hard:
        numRows = static_cast<int>(getRandomValue(4, 6)) + 2;
        numColumns = static_cast<int>(getRandomValue(4, 6)) + 2;
        break;
    }

    // Calculate total rooms and types of rooms
    int totalRooms = numRows * numColumns;
    int numEmptyRooms = ((totalRooms - 4) / 2) + 2;
    int numMonsterRooms = (totalRooms % 2) ? (numEmptyRooms) : numEmptyRooms - 1;

    // Create and shuffle rooms
    treasureRoomLocation = new TreasureRoom();
    rooms.push_back(treasureRoomLocation);
    for (int i = 0; i < numEmptyRooms; ++i) {
        rooms.push_back(new EmptyRoom());
    }
    for (int i = 0; i < numMonsterRooms; ++i) {
        rooms.push_back(new MonsterRoom());
    }
    std::shuffle(rooms.begin(), rooms.end(), std::mt19937(std::random_device()()));

    // Set start room and initialize visited grid
    do {
        int randomIndex = static_cast<int>(getRandomValue(0, rooms.size() - 1));
        startRoom = rooms[randomIndex];
    } while (startRoom->getType() == "TreasureRoom");
    visited = std::vector<std::vector<bool>>(static_cast<size_t>(numRows), std::vector<bool>(static_cast<size_t>(numColumns), false));

    // Connect rooms
    for (int row = 0; row < numRows; row++) {
        for (int column = 0; column < numColumns; column++) {
            int currentIndex = row * numColumns + column;
            if (column < numColumns - 1) {
                connectRooms(rooms[currentIndex], rooms[currentIndex + 1], Direction::East);
            }
            else {
                connectRooms(rooms[currentIndex], rooms[row * numColumns], Direction::East);
            }
            if (row < numRows - 1) {
                connectRooms(rooms[currentIndex], rooms[currentIndex + numColumns], Direction::South);
            }
            else {
                connectRooms(rooms[currentIndex], rooms[column], Direction::South);
            }
        }
    }
}

// Connect two rooms
void Dungeon::connectRooms(Room* room1, Room* room2, Direction direction) {
    room1->addConnection(room2, direction);
    Direction oppositeDir = static_cast<Direction>(3 - static_cast<int>(direction));
    room2->addConnection(room1, oppositeDir);
}

// Display dungeon layout with current Monk's position
void Dungeon::displayDungeon(Monk* currentMonk) {
    int bracketWidth = 5;
    for (int row = 0; row < numRows; row++) {
        for (int column = 0; column < numColumns; column++) {
            if (visited[row][column]) {
                Room* currentRoom = rooms[row * numColumns + column];
                std::string type = currentRoom->getType();
                char firstChar = type.empty() ? ' ' : type[0];
                if (currentRoom == currentMonk->getCurrentPosition()) {
                    firstChar = std::toupper(firstChar);
                }
                else {
                    firstChar = std::tolower(firstChar);
                }
                int leftPadding = (bracketWidth - 1) / 2;
                int rightPadding = bracketWidth - 1 - leftPadding;
                std::cout << "[" << std::setw(leftPadding) << "" << firstChar << std::setw(rightPadding) << "" << "]";
            }
            else {
                std::cout << "[" << std::setw(bracketWidth) << "" << "]";
            }
        }
        std::cout << std::endl;
    }
}

// Display dungeon layout with all room types in uppercase
void Dungeon::displayDungeonAllCaps() {
    int bracketWidth = 5;
    for (int row = 0; row < numRows; row++) {
        for (int column = 0; column < numColumns; column++) {
            Room* currentRoom = rooms[row * numColumns + column];
            std::string type = currentRoom->getType();
            char displayChar = type.empty() ? ' ' : toupper(type[0]);
            int leftPadding = (bracketWidth - 1) / 2;
            int rightPadding = bracketWidth - 1 - leftPadding;
            std::cout << "[" << std::setw(leftPadding) << "" << displayChar << std::setw(rightPadding) << "" << "]";
        }
        std::cout << std::endl;
    }
}

// Display dungeon statistics
void Dungeon::displayDungeonStats() {
    std::cout << "Total Rooms: " << numRows * numColumns << std::endl;
    std::cout << "Dungeon Dimensions: " << numColumns << "x" << numRows << std::endl;
    std::cout << "Difficulty Level: " << static_cast<int>(difficulty) << std::endl;
}

// Update visited grid based on current room
void Dungeon::updateVisited(Room* room) {
    for (int row = 0; row < numRows; row++) {
        for (int column = 0; column < numColumns; column++) {
            if (rooms[row * numColumns + column] == room) {
                visited[row][column] = true;
                return;
            }
        }
    }
}

// Destructor to free allocated memory
Dungeon::~Dungeon() {
    for (Room* room : rooms) {
        delete room;
    }
    rooms.clear();
}
