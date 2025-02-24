#ifndef INPUT
#define INPUT

#include <stdbool.h>
#include <stddef.h>

void get_user_input_str(const char* msg, char* buffer, size_t size, bool (*validate)(const char*));
int get_user_input_int(char* msg, bool (*validate)(const int));
char get_user_input_char(char* msg);

#endif
