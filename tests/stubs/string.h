#ifndef DS45_TEST_STRING_H
#define DS45_TEST_STRING_H
#include <stddef.h>
void *memset(void *, int, size_t);
void *memcpy(void *, const void *, size_t);
char *strchr(const char *, int);
int strcmp(const char *, const char *);
#endif
