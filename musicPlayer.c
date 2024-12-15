#include <stdio.h>
#include <stdlib.h>

#define charSize 100

struct Song {
    char songName[charSize];
    char artist[charSize];
}; 

struct Node {
    // actual data to be stored
    struct Song song;
    // pointer to next node
    struct Node* next;
    // pointer to previous node
    struct Node* prev;
};

typedef struct Node node;


int main(void) {

    // declare songs 
    struct Song song1 = {"All Time Low", "Jon Bellion"};
    struct Song song2 = {"Father Time", "Kendrick Lamar"};
    struct Song song3 = {"Savior", "Rise Against"};
    struct Song song4 = {"Immortal", "J Cole"};
 
    // create nodes
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node4 = (struct Node*)malloc(sizeof(struct Node));

    // dereference nodes to songs
    node1->song = song1;
    node2->song = song2;
    node3->song = song3;
    node4->song = song4;

    // assign nodes to eachother
    node1->next = node2;
    node2->prev = node1;

    node2->next = node3;
    node3->prev = node2;

    node3->next = node4;
    node4->prev = node3;

    //cout menu
    //show current song
    //play next
    //play last
    //end of plalist
    // cycle through nodes to show they are connected
    //remove a song
    return 0;
}