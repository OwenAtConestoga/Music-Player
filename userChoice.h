#ifndef userChoice
#define userChoice
#include <stdio.h>

int getUserChoice(void) {
    int choice;
    char buffer[100];

    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &choice) == 1) {
                if (choice >= 1 && choice <= 7) {
                    return choice;
                }
            }
        }
        printf("Invalid input. Please enter a number between 1-6: ");
    }
}

#endif