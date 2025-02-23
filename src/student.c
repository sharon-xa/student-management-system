#include "input.h"
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char first_name[25];
    char last_name[25];
    char date_of_birth[11]; // YYYY-MM-DD format
    char gender[10];
    char address[255];
    char department[50];
};

void add_student() {
    struct Student s;
    s.id = getUserInputInt("Enter id");
    getUserInputStr("Enter student name", s.first_name, sizeof(s.first_name));
}
