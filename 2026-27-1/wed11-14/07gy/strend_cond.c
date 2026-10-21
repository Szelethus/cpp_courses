#include <stdio.h>

const char* getEnd(const char *str) {
  if (*str == '\0')
    return NULL;

  const char *end = str;
  while (*(end + 1) != '\0')
    ++end;

  return end;
}

int main() {
  char str[] = "123";

  const char *end = getEnd(str);

  printf("%c\n", *end);
}
