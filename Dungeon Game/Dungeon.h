// ifndef checks if the identifier DUNGEON_H has not been defined yet
#ifndef DUNGEON_H
// ifndef block starts here

// define the identifier DUNGEON_H to prevent double inclusion of the header file
#define DUNGEON_H

// include necessary headers
#include <vector>        // for std::vector
#include "Room.h"       // include Room header
#include "Difficulty.h" // include Difficulty header
#include "Monk.h"       // include Monk header

// Dungeon class declaration
class Dungeon {
private:
    // private static instance variable for singleton pattern
    static Dungeon* instance;

    // private constructor to prevent direct instantiation
    Dungeon();

    // private member variables
    std::vector<Room*> rooms;              // vector of Room pointers
    Room* startRoom;                       // pointer to the start room
    Room* treasureRoomLocation;            // pointer to the treasure room location
    std::vector<std::vector<bool>> visited; // 2D vector to track visited rooms

    size_t numColumns;                     // number of columns in the dungeon grid
    size_t numRows;                        // number of rows in the dungeon grid
    Difficulty difficulty;                 // difficulty level of the dungeon

public:
    // public static method to get the singleton instance of Dungeon
    static Dungeon* getInstance();

    // public member functions
    const std::vector<Room*>& getRooms() const;  // get method for rooms vector
    Room* getStartRoom();                        // get method for startRoom
    Room* getTreasureRoomLocation();              // get method for treasureRoomLocation
    Difficulty getDifficulty();                  // get method for difficulty

    void setStartRoom(Room* room);               // set method for startRoom
    void setDifficulty(Difficulty set_difficulty); // set method for difficulty

    // dungeon generation and display methods
    void generateDungeon();                      // method to generate the dungeon
    void connectRooms(Room* room1, Room* room2, Direction direction); // method to connect two rooms
    void displayDungeon(Monk* currentMonk);       // method to display the dungeon
    void displayDungeonAllCaps();                 // method to display the dungeon in all caps
    void displayDungeonStats();                   // method to display dungeon statistics
    void updateVisited(Room* room);               // method to update visited status of a room

    // destructor
    ~Dungeon();
};

// endif closes the ifndef block
#endif // DUNGEON_H
// comment indicating the end of the ifndef block
