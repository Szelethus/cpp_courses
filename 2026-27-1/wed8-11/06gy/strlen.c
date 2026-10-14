#include <stdio.h>

size_t my_strlen(const char *str) {
  size_t i = 0;
  while (str[i] != '\0') {
    ++i;
  }

  return i;
}

int main() {
  char str[] = "almafa pite";

  size_t size = my_strlen(str);

  // z: singed size_t
  // u: unsigned
  printf("%zu\n", size);
}
