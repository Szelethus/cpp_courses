#include <stdio.h>

int my_strlen(const char *str) {
  int i = 0;
  while (str[i] != '\0') {
    ++i;
  }
  return i;
}

int main() {
  const char *str = "Alma";

  int size = my_strlen(str);

  printf("%d\n", size);
}
