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

void removeSong(struct Node** head, char* songName) {
    // Case 1: if the list is empty, there is nothing to remove (no head)
    if (*head == NULL) {
        printf("List is empty, no songs to remove\n");
        return;
    }

    // node parser
    struct Node* current = *head;

    // Case 2: if the first node is the one we want to remove
    /* before
    Copy[Head] -> [Node1] -> [Node2] -> NULL
          current
    After
    [Head] -> [Node2] -> NULL */
   
    if (strcmp(current->song.songName, songName) == 0) {
        // move head to the next node
        *head = current->next;
        // if there was another node
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(current);
        return;
    }

    // Case 3: if the song is somewhere in the middle or end
    while (current != NULL) {
        // check if song name matches one to delete
        if (strcmp(current->song.songName, songName) == 0) {  
            //change prev node NEXT pointer to skip current
            // song1-> song3 instead of song2
            current->prev->next = current->next;

            // if not the last node, update prev pointer of next node
            if (current->next != NULL) {
                // change next node PREV pointer to skip current
                // song3->prev song1 instead of song2
                current->next->prev = current->prev;
            }
            free(current);
            return;
        }
        // move to next song to continue searching
        current = current->next;
    }
    
    // nothing was found
    printf("Song '%s' not found in the playlist\n", songName);
}

// move to next song
void playNextSong(struct Node** current){
    if (*current == NULL){
        printf("No songs in playlist\n");
        return;
    }    
    if ((*current)->next != NULL){
        *current = (*current)->next;
        getCurrentSong(*current);        
    } else{
        printf("End of playlist\n");
    }
}

// play previous song
void playPreviousSong(struct Node** current) {
    if (*current == NULL) {
        printf("No songs in playlist!\n");
        return;
    }
    if ((*current)->prev != NULL) {
        *current = (*current)->prev;
        getCurrentSong(*current);
    } else {
        printf("Already at start of playlist!\n");
    }
}

// Print entire playlist
void printPlaylist(struct Node* head) {
    struct Node* current = head;
    int songNumber = 1;
    
    if (head == NULL) {
        printf("Playlist is empty!\n");
        return;
    }
    
    printf("\n=== Current Playlist ===\n");
    while (current != NULL) {
        printf("%d. %s - %s\n", 
               songNumber++, 
               current->song.songName, 
               current->song.artist);
        current = current->next;
    }
    printf("=====================\n");
}

void getCurrentSong(struct Node* current) {
    if (current == NULL) {
        printf("No song is currently playing\n");
        return;
    }
    printf("Now Playing: %s by %s\n", 
           current->song.songName, 
           current->song.artist);
}
