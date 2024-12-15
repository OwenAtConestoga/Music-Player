#ifndef menu
#define menu 

#include <stdio.h>


void displayWelcome(void) {
    printf("\n");
    printf("  ╔══════════════════════════════════════╗\n");
    printf("  ║           MUSIC  PLAYER              ║\n");
    printf("  ╚══════════════════════════════════════╝\n");
}

void displayMenu(void) {
    printf("\n");
    printf("  ┌────────── MENU ─────────────┐\n");
    printf("  │  1. Show Current Song       │\n");
    printf("  │  2. Play Next Song          │\n");
    printf("  │  3. Play Previous Song      │\n");
    printf("  │  4. Remove Current Song     │\n");
    printf("  │  5. Add New Song            │\n");
    printf("  │  6. Show all songs          │\n");
    printf("  │  7. Quit                    │\n");
    printf("  └─────────────────────────────┘\n");
    printf("\n  Enter your choice (1-7): ");
}

#endif

