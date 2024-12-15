#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "songs.h"

struct Node {
    // actual data to be stored
    struct Song song;
    // pointer to next node
    struct Node* next;
    // pointer to previous node
    struct Node* prev;
};

struct PlaylistState {
    struct Node* head;     // Start of playlist
    struct Node* current;  // Currently playing song
};


typedef struct Node node;

void addSong(struct Node** head, struct Song song);

void removeSong(struct Node** head, char* songName);

void playNextSong(struct Node** current);

void playPreviousSong(struct Node** current);

void printPlaylist(struct Node* head, struct Node* current);

void getCurrentSong(struct Node* current);

void cleanupPlaylist(struct Node* head);

#endif