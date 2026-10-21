#include <stdio.h>

const char* getEnd(const char *str) {
  if (*str == '\0')
    return NULL;

  const char *ret = str;

  while (*(ret + 1) != '\0')
    ++ret;

  return ret;
}

int main() {
  char str[] = "Hello";

  const char *end = getEnd(str);

  printf("%c\n", *end);
}
