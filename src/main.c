#include "input.h"
#include "student.h"
#include "ui.h"
#include <stdio.h>
#include <stdlib.h>

void start_program() {
    char userChoice;
    do {
        printf("\n");
        print_program_instruction();
        userChoice = get_user_input_char("Enter option");

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
    start_program();
    return 0;
}
