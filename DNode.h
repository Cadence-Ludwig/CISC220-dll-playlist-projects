//
// Created by celud on 9/22/2026.
//

#ifndef DLLPLAYLISTPROJECT_DNODE_H
#define DLLPLAYLISTPROJECT_DNODE_H


#include <stdlib.h>
#include "Song.h"
using namespace std;

class DNode {
    friend class DLL;  // gives the DLL class access to the private fields
    Song *song;
    DNode *prev;
    DNode *next;
public:
    DNode();
    DNode(string s, string a, int lenmin, int lensec);
    DNode(Song *s);
    void print() const;
};



#endif //DLLPLAYLISTPROJECT_DNODE_H
