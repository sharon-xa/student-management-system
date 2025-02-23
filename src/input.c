#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getUserInputStr(const char* msg, char* buffer, size_t size) {
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
}

int getUserInputInt(char* msg) {
    printf("%s: ", msg);

    int input;
    if (scanf("%d", &input) != 1) {
        printf("Error: Invalid input\n");
        exit(1);
    }

    while (getchar() != '\n');
    return input;
}

char getUserInputChar(char* msg) {
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
