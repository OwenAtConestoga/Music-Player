
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>  
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

void addSong(struct Node** head, struct Song song);

void removeSong(struct Node** head, char* songName);

void playNextSong(struct Node** current);

void playPreviousSong(struct Node** current);

void printPlaylist(struct Node* head);

void getCurrentSong(struct Node* current);

#endif