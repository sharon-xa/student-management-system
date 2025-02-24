#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_user_input_str(const char* msg, char* buffer, size_t size, bool (*validate)(const char*)) {
    printf("%s: ", msg);

    if (fgets(buffer, size, stdin) == NULL) {
        printf("Error: Failed to read input.\n");
        return;
    }

    size_t len = strcspn(buffer, "\n");
    if (buffer[len] == '\n') {
        buffer[len] = '\0';
    } else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    if (!validate(buffer)) {
        printf("bad input, please try again\n");
        get_user_input_str(msg, buffer, size, validate);
    }
}

int get_user_input_int(char* msg, bool (*validate)(const int)) {
    printf("%s: ", msg);

    int input;
    if (scanf("%d", &input) != 1) {
        printf("Error: Invalid input\n");
    }

    while (getchar() != '\n');

    while (!validate(input)) {
        printf("bad input, please try again\n");

        printf("%s: ", msg);
        scanf("%d", &input);
        while (getchar() != '\n');
    }

    return input;
}

char get_user_input_char(char* msg) {
    printf("%s: ", msg);

    char input;
    if (scanf(" %c", &input) != 1) {
        printf("Error: Invalid input\n");
        exit(1);
    }

    while (getchar() != '\n');
    printf("\n");
    return input;
}
