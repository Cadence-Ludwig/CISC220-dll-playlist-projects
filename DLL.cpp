//
// Created by celud on 9/22/2026.
//

#include "DNode.h"
#include "DLL.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

//Check Playlist.cpp for instructions of what to write here and how to test it

DLL::DLL(){  // constructor - initializes an empty list
    last = NULL;
    first = NULL;
    numSongs = 0;
}
DLL::DLL(string t, string l, int m, int s){  // constructor, initializes a list with one new node with data x
    DNode *n = new DNode (t,l,m,s);
    first = n;
    last = n;
    numSongs=1;
}

void DLL::push(string n, string a, int m, int s) {  // does what you'd think

}
Song *DLL::pop() { //does what you'd think
}

void DLL::printList() {
}

void DLL::moveUp(string s) {
}

void DLL::listDuration(int *tm, int *ts) {
}
void DLL::moveDown(string s) {
}
void DLL::makeRandom() {
}
int DLL::remove(string s) {
    // note that the int returned is the index - this is standard for a remove, but we won't be using it.
}


DLL::~DLL() {  //5 pts EC - this is the destructor
    for (DNode *tmp = first->next; tmp != NULL; tmp = tmp->next) {
        delete tmp->prev;
    }
    delete last;
}

