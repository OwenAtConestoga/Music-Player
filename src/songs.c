#include "songs.h"
#include <string.h>

void createSong(struct Song* song, char* songName, char* artist) {
    strcpy(song->songName, songName);
    strcpy(song->artist, artist);
}