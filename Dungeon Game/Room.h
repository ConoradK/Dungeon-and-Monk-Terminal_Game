// ifndef checks if the identifier ROOM_H has not been defined yet
#ifndef ROOM_H
// ifndef block starts here

// define the identifier ROOM_H to prevent double inclusion of the header file
#define ROOM_H

// include necessary headers
#include <string>         // include string header
#include "Direction.h"    // include Direction header

// Room class declaration
class Room {
public:
    // public constructor with parameter
    Room(std::string t);

    // virtual destructor
    virtual ~Room();

    // Getter methods
    std::string getType() const;        // get method for type
    Room** getConnectedRooms();          // get method for connectedRooms array

    // Method to add a connection to another room
    void addConnection(Room* room, Direction direction);

    // Virtual method to display room information
    virtual void displayRoomInfo();

    // Setter methods
    void setType(std::string t);          // set method for type
    void setConnectedRoom(Room* room, Direction direction);  // set method for connectedRooms

private:
    // private member variables
    std::string type;                     // room type
    Room* connectedRooms[4];              // array to store pointers to connected rooms
};

// endif closes the ifndef block
#endif // ROOM_H
// comment indicating the end of the ifndef block
