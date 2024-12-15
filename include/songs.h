#ifndef SONGS_H
#define SONGS_H

#define charSize 100

struct Song {
    char songName[charSize];
    char artist[charSize];
};

// Just the declaration (prototype)
void createSong(struct Song* song, char* songName, char* artist);

#endif