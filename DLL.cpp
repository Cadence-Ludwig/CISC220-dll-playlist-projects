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
        //cout << "list->last==NULL" << endl;
        return NULL;
    } else {
        //cout << "list->last!=NULL" << endl;
        Song *data = last->song;
        //cout<<"previous line does not break"<<endl;
        numSongs--;
        //data->printSong();
        last = last->prev;
        delete last->next;
        last->next = NULL;
        //data->printSong();
        return data;
    }
}

void DLL::printList() {
    for (DNode *tmp = first; tmp != NULL; tmp = tmp->next) {
        tmp->song->printSong();
    }//for
    cout << endl;
}

void DLL::moveUp(string s) {
    DNode *tmp = first;
    for (tmp; tmp != NULL; tmp = tmp->next) {
        if (tmp->song->title == s) {break;}
    }//for
    if (tmp->song->title != s) return;
    cout << "Moving " << s << "  up one" << endl;
    if (tmp == first) {
        first = last;
        last = tmp;
        last->prev=first->prev;
        first->next = last->next;
        last->next = NULL;
        first->prev = NULL;
    } else {
        DNode *tmp2 = tmp->prev;
        tmp->prev->next = tmp->next;
        tmp->prev->prev=tmp;
        tmp->prev=tmp;
        tmp->next=tmp2->next;
        tmp->prev=tmp2->prev;
        tmp=tmp2;
    }//else
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
    DNode *tmp = first;
    for (tmp; tmp != NULL; tmp = tmp->next) {
        if (tmp->song->title == s) {break;}
    }//for
    if (tmp->song->title != s) return;
    cout << "Moving " << s << "  down one" << endl;
    if (tmp == last) {
        last = first;
        first = tmp;
        first->next=last->next;
        last->prev = first->prev;
        first->prev = NULL;
        last->next = NULL;
    } else {
        DNode *tmp2 = tmp->next;
        tmp->next->prev = tmp->prev;
        tmp->next->next=tmp;
        tmp->next=tmp;
        tmp->prev=tmp2->prev;
        tmp->next=tmp2->next;
        tmp=tmp2;
    }//else
    printList();
}
void DLL::makeRandom() {
}
int DLL::remove(string s) {
    // note that the int returned is the index - this is standard for a remove, but we won't be using it.
    int i=0;
    for (DNode *tmp = first; tmp != NULL; tmp = tmp->next) {
        if (tmp->song->title == s) {
            if (tmp != first) tmp->prev->next = tmp->next;
            if (tmp != last) tmp->next->prev = tmp->prev;
            cout << "Removing: ";
            tmp->song->printSong();
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

