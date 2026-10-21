#include <stdio.h>

void getEnd(const char *str,
            const char **end) {
  if (*str == '\0')
    *end = NULL;

  const char *it = str;
  while (*(it + 1) != '\0')
    ++it;

  *end = it;
}

int main() {
  char str[] = "123";

  const char *end;
  getEnd(str, &end);

  printf("%c\n", *end);
}
