//
// Created by celud on 9/22/2026.
//

#include "DNode.h"
DNode::DNode() {
    song=NULL;//maybe this should initialize to new Song() instead of NULL...
    prev=NULL;
    next=NULL;
}
DNode::DNode(string s, string a, int lenmin, int lensec) {
    song=new Song(s,a,lenmin,lensec);
    prev=NULL;
    next=NULL;
}
DNode::~DNode() {
    
}