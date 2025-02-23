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

    buffer[strcspn(buffer, "\n")] = '\0';
}

int getUserInputInt(char* msg) {
    printf("%s: ", msg);

    int input;
    if (scanf("%d", &input) != 1) {
        printf("Error: Invalid input\n");
        exit(1);
    }

    return input;
}

char getUserInputChar(char* msg) {
    printf("%s: ", msg);

    char input;
    if (scanf(" %c", &input) != 1) {
        printf("Error: Invalid input\n");
        exit(1);
    }

    printf("\n");
    return input;
}
