#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Room.h"
#include <iostream>
#include <string>
#include "ship.h"
using namespace std;

class ZorkUL {
    friend class MainWindow;
private:
	Room *currentRoom;
    void createRooms();
    Room *my_rooms[9];
    string my_roomsDes[9];
public:
	ZorkUL();
    ~ZorkUL();

};

#endif /*ZORKUL_H_*/
