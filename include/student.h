#ifndef STUDENT
#define STUDENT

struct Student {
    int id;
    char first_name[25];
    char last_name[25];
    char date_of_birth[11]; // YYYY-MM-DD format
    char address[255];
    char department[50];
};

void add_student();

#endif
