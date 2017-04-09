#include <iostream>

using namespace std;
#include "ZorkUL.h"
#include <cstring>


ZorkUL::ZorkUL() {
    createRooms();
}

void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i;
   // Ship enemyb,enemyd,enemyf;

    a = new Room("a");
    b = new Room("b");
        b->addItem(new Item("Kestrel"));
        b->addItem(new Item("Lasers"));
    c = new Room("c");
        c->addItem(new Item("power +5"));
    d = new Room("d");
        d->addItem(new Item("Engi"));
    e = new Room("e");
        e->addItem(new Item("door"));
    f = new Room("f");
        f->addItem(new Item("Federation"));
    g = new Room("g");
        g->addItem(new Item("power +10"));
    h = new Room("h");
        h->addItem(new Item("key"));
    i = new Room("i");
        i->addItem(new Item("power +10"));


//             (N, E, S, W)
    a->setExits(f, b, d, c);
    b->setExits(NULL, NULL, NULL, a);
    c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, NULL, i);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(NULL, g, a, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);
        currentRoom = a;
    my_rooms[0] = a;
    my_rooms[1] = b;
    my_rooms[2] = c;
    my_rooms[3] = d;
    my_rooms[4] = e;
    my_rooms[5] = f;
    my_rooms[6] = g;
    my_rooms[7] = h;
    my_rooms[8] = i;

    my_roomsDes[0] = "a";

    my_roomsDes[1] = "b";
    my_roomsDes[2] = "c";
    my_roomsDes[3] = "d";
    my_roomsDes[4] = "e";
    my_roomsDes[5] = "f";
    my_roomsDes[6] = "g";
    my_roomsDes[7] = "h";
    my_roomsDes[8] = "i";


}
ZorkUL::~ZorkUL(){
    cout<<"bye zorkUL"<<endl;
}

