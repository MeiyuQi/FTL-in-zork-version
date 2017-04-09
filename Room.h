#ifndef ROOM_H_
#define ROOM_H_
#include "item.h"
#include <map>
#include <string>
#include <vector>
using namespace std;
using std::vector;

class Room {

    friend class MainWindow;
private:
    string description;
    map<string, Room*> exits;
    string exitString();
    vector<Item> itemsInRoom;



public:
    int numberOfItems();
    Room(string description);
    ~Room();
    void setExits(Room *north, Room *east, Room *south, Room *west);
    string shortDescription();
    string longDescription();
    Room* nextRoom(string direction);
    void addItem(Item *inItem);
    string displayItem();
    int isItemInRoom(string inString);
    void removeItemFromRoom(int location);
};

#endif
