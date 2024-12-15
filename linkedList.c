#include <stdio.h>
#include <stdlib.h>  
#include "songs.h"
#include "linkedList.h"


// Function takes double pointer to head (so we can modify the original list pointer)
// and a Song structure (the song data we want to add)
void addSong(struct Node** head, struct Song song){
    struct Node* newNode = malloc(sizeof(struct Node));
    // new node, copy song data into it
    newNode->song = song;
    // initialize next and prev pointers to NULL
    newNode->next = NULL;
    newNode->prev = NULL;

    // if the list is empty... 
    if (*head == NULL){
        // head points to our new node
        *head = newNode;
        return;
    }

    // find end and attatch node there
    /* First: current points here
    [Node1] -> [Node2] -> [Node3] -> NULL
      ⬆
    current

    After loop: current moved to end
    [Node1] -> [Node2] -> [Node3] -> NULL
                            ⬆ 
                         current */

    // if the list ISNT empty...
    else{
        // walk the list
        struct Node* current = *head;  

        while (current->next != NULL) {
        current = current->next;
    }
    
    // Connect new node to the end
    current->next = newNode;
    newNode->prev = current;
    }
}

void removeSong(struct Node** head, char* songName);

