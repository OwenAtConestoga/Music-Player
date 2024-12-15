#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "songs.h"
#include "linkedList.h"
#include "userChoice.h"

int main() {
    struct PlaylistState* playlist = initializePlaylist();
    int choice;
    
    displayWelcome();
    
    while (1) {
        displayMenu();
        choice = getUserChoice();
        
        switch(choice) {
            case 1: // Show current
                getCurrentSong(playlist->current);
                break;
                
            case 2: // Next song
                playNextSong(&playlist->current);
                break;
                
            case 3: // Previous song
                playPreviousSong(&playlist->current);
                break;
                
            case 4: { // Remove current
                if (playlist->current != NULL) {
                    char* songToRemove = playlist->current->song.songName;
                    struct Node* nextSong = playlist->current->next;
                    
                    removeSong(&playlist->head, songToRemove);
                    playlist->current = nextSong;
                    if (playlist->current == NULL && playlist->head != NULL) {
                        playlist->current = playlist->head; // Reset to start if we removed last song
                    }
                }
                break;
            }
                
            case 5: { // Add new song
                struct Song newSong;
                char songName[100], artist[100];
                
                printf("Enter song name: ");
                while (getchar() != '\n'); // Clear buffer
                fgets(songName, sizeof(songName), stdin);
                songName[strcspn(songName, "\n")] = 0; // Remove newline
                
                printf("Enter artist: ");
                fgets(artist, sizeof(artist), stdin);
                artist[strcspn(artist, "\n")] = 0; // Remove newline
                
                createSong(&newSong, songName, artist);
                addSong(&playlist->head, newSong); 
                if (playlist->current == NULL) {
                    playlist->current = playlist->head;
                }
                printPlaylist(playlist->head, playlist->current);
                break;
            }
                
            case 6: // Quit
                printf("\nThanks for using Music Player!\n");
                cleanupPlaylist(playlist->head);
                free(playlist);
                return 0;
        }
    }
    return 0;
}