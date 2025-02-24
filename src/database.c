#include "student.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATABASE_LOCATION "data/students.txt"
#define MAX_LINES 1000
#define MAX_LINE_LENGTH 512

void store_student(struct Student* s) {
    FILE* f = fopen(DATABASE_LOCATION, "a");
    if (f == NULL) {
        printf("failed to open the database file.\n");
        exit(1);
    }

    fprintf(f, "%d|%s|%s|%s|%s|%s\n", s->id, s->first_name, s->last_name, s->date_of_birth,
            s->address, s->department);

    fclose(f);
}

struct Student* parse_student(char* studentStr) {
    static struct Student s;
    for (size_t i = 1;; i++) {
        char* token = strsep(&studentStr, "|");
        if (token == NULL)
            break;

        switch (i) {
            case 1:
                s.id = atoi(token);
                break;
            case 2:
                strcpy(s.first_name, token);
                break;
            case 3:
                strcpy(s.last_name, token);
                break;
            case 4:
                strcpy(s.date_of_birth, token);
                break;
            case 5:
                strcpy(s.address, token);
                break;
            case 6:
                strcpy(s.department, token);
                break;
        }
    }

    return &s;
}

char* get_last_record() {
    FILE* f = fopen(DATABASE_LOCATION, "r");
    if (f == NULL) {
        printf("failed to open the database file.\n");
        exit(1);
    }

    char* arr_of_lines[MAX_LINES] = {};
    char buff[MAX_LINE_LENGTH];
    int line_number = 0;
    while (fgets(buff, sizeof(buff), f) != NULL && line_number < MAX_LINE_LENGTH) {
        arr_of_lines[line_number] = strdup(buff);
        if (!arr_of_lines[line_number]) {
            perror("Memory allocation failed");
            break;
        }
        line_number++;
    }
    fclose(f);

    char* last_line = strdup(arr_of_lines[line_number - 1]);
    for (int i = 0; i < line_number; i++) {
        free(arr_of_lines[i]);
    }

    return last_line;
}

unsigned int fetch_last_id() {
    char* last_record = get_last_record();
    struct Student* s = parse_student(last_record);
    return s->id;
}
