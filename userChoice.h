#ifndef userChoice
#define userChoice
#include <stdio.h>

int getUserChoice(void) {
    int choice;
    scanf("%d", &choice);
    return choice;
}

#endif