//
// Created by celud on 9/22/2026.
//

#ifndef DLLPLAYLISTPROJECT_SONG_H
#define DLLPLAYLISTPROJECT_SONG_H


#include <iostream>
#include <stdlib.h>
using namespace std;

class Song {
    friend class DNode;  //Gives DNode class access to private f
    friend class DLL; //Gives DLL class access to private fields
    string title;  //title
    string artist;  //song artist name
    int min;  // for the number of total minutes
    int sec;  // for the leftover number of seconds
public:
    Song(string t, string a, int m, int s);
    Song();
    void printSong();
};



#endif //DLLPLAYLISTPROJECT_SONG_H
