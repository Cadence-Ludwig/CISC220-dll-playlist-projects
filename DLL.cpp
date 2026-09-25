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
    DNode *tmp = new DNode (n,a,m,s);
    if (first == NULL) {
        //this is for the case where the list does not have a first node
        first = tmp;
        if (last != NULL) {
            cout << "A DLL with a last node and no first node has been encountered, something is wrong" << endl;
        }//if
        last = tmp;
        numSongs++;
        return;
    }//if
    last->next = tmp;
    tmp->prev = last;
    last = tmp;
    numSongs++;
}
Song *DLL::pop() { //does what you'd think
    if (last == NULL) {
        cout << "list->last==NULL" << endl;
        return NULL;
    }//if
    cout << "list->last!=NULL" << endl;
    Song *data = last->song;
    cout << "before deleting list->last" << endl;
    data->printSong();
    last->prev->next = NULL;
    delete last;
    cout << "after deleting list->last";
    //well, after deleting last... last->song is also deleted
    //but we need that to keep existing so we can return it...
    data->printSong();
    numSongs--;
    return data;
}

void DLL::printList() {
    for (DNode *tmp = first; tmp != NULL; tmp = tmp->next) {
        tmp->song->printSong();
    }//for
    cout << endl;
}

void DLL::moveUp(string s) {
}

void DLL::listDuration(int *tm, int *ts) {
    for (DNode *tmp = first; tmp != NULL; tmp = tmp->next) {
        *tm += tmp->song->min;
        *ts += tmp->song->sec;
    }//for
    *tm += *ts/60;//don't worry, division isn't typecasting anything to a float
    *ts %= 60;
}
void DLL::moveDown(string s) {
}
void DLL::makeRandom() {
}
int DLL::remove(string s) {
    // note that the int returned is the index - this is standard for a remove, but we won't be using it.
    int i=0;
    for (DNode *tmp = first; tmp != NULL; tmp = tmp->next) {
        if (tmp->song->title == s) {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            delete tmp;//not sure if this will work from this scope
            numSongs--;
            return i;
        }//if
        i++;
    }//for
    return -1;
}


DLL::~DLL() {  //5 pts EC - this is the destructor
    for (DNode *tmp = first->next; tmp != NULL; tmp = tmp->next) {
        delete tmp->prev;
        //I think we would lose access to tmp->next if we deleted tmp itself
    }//for
    delete last; //NULL->prev is not last, so this can't happen in the loop itself
}

