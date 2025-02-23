#include "input.h"
#include "student.h"
#include "ui.h"
#include <stdio.h>
#include <stdlib.h>

void startProgram() {
    char userChoice;
    do {
        printf("\n");
        printProgramInstruction();
        userChoice = getUserInputChar("Enter option");

        switch (userChoice) {
            case '1':
                add_student();
                break;
            case '2':
                printf("remove a student");
                break;
            case '3':
                printf("search a student");
                break;
            case '4':
                printf("show all students");
                break;
            case '5':
                printf("show a student by id");
                break;
            case '6':
                system("clear");
                break;
            case 'q':
                exit(0);
                break;
            case 'Q':
                exit(0);
                break;
            default:
                printf("invalid input");
                break;
        }
    } while (1);
}

int main() {
    startProgram();
    return 0;
}
