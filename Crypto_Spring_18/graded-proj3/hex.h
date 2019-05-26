
#ifndef HEX_H
#define HEX_H
#include <stdlib.h>
#include <string.h>

size_t hexs2bin(const char *hex, unsigned char **out);
char *bin2hex(const unsigned char *bin, size_t len);
int hexchr2bin(const char hex, char *out);

#endif
