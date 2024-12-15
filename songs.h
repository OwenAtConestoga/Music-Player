# ifndef songs
#define songs

#include <stdio.h>
#include <string.h>

#define charSize 100

struct Song {
    char songName[charSize];
    char artist[charSize];
}; 

void createSong(struct Song* song, char* songName, char* artist){
    strcpy(song->songName, songName);
    strcpy(song->artist, artist);
}    



#endif
