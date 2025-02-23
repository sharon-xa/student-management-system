#ifndef INPUT
#define INPUT

#include <stddef.h>
void getUserInputStr(const char* msg, char* buffer, size_t size);
int getUserInputInt(char* msg);
char getUserInputChar(char* msg);

#endif
