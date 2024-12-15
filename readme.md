# Music Player Implementation

A command-line music playlist manager implemented in C to practice doubly linked list data structures. This project demonstrates basic playlist functionality using linked list operations.

## Features
- Add songs to playlist
- Play next/previous song
- Remove current song
- View current playing song
- Display full playlist
- Basic playlist navigation

## Implementation Details
- Uses doubly linked list for playlist management
- Each node contains song information (name and artist)
- Maintains current playing song pointer
- Memory management for adding/removing songs

## Functions
- `addSong`: Adds a new song to end of playlist
- `removeSong`: Removes specified song from playlist
- `playNextSong`: Moves to next song in playlist
- `playPreviousSong`: Moves to previous song in playlist
- `getCurrentSong`: Shows currently playing song
- `printPlaylist`: Displays all songs in playlist

## How to Run
```bash
gcc musicPlayer.c linkedList.c songs.c -o musicPlayer
./musicPlayer