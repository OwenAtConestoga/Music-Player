#ifndef userChoice
#define userChoice
#include <stdio.h>

int getUserChoice(void) {
    int choice;
    while(1) {
        if(scanf("%d", &choice) == 1) {
            if(choice >= 1 && choice <= 6) {
                return choice;
            }
        }
        printf("Invalid choice. Please enter 1-6: ");
        while(getchar() != '\n'); // Clear input buffer
    }
}

#endif