#include <stdio.h>

int main() {
  char str[6];
  fgets(str, sizeof(str), stdin);
  printf("%s\n", str);
}
