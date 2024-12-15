
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "songs.h"

struct Node {
    // actual data to be stored
    struct Song song;
    // pointer to next node
    struct Node* next;
    // pointer to previous node
    struct Node* prev;
};

typedef struct Node node;



#endif