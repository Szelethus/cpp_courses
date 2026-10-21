#include <stdio.h>

void getEnd(const char *str,
            const char **end) {
  if (*str == '\0')
    *end = NULL;

  const char *ret = str;

  while (*(ret + 1) != '\0')
    ++ret;

  *end = ret;
}

int main() {
  char str[] = "Hello";

  const char *end;
  getEnd(str, &end);

  printf("%c\n", *end);
}
