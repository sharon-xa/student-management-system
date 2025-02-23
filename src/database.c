#include "student.h"
#include <stdio.h>
#include <stdlib.h>

void store_student(struct Student* s) {
    FILE* f = fopen("data/students.txt", "a");
    if (f == NULL) {
        printf("failed to open the database file\n");
        exit(1);
    }

    fprintf(f, "%d|%s|%s|%s|%s|%s\n", s->id, s->first_name, s->last_name, s->date_of_birth,
            s->address, s->department);

    fclose(f);
}
