#include <stdio.h>

int main() {
  char c;
  while (scanf(" %c", &c) == 1) {
    if (c >= 'A' && c <= 'Z')
      printf("%c\n", c + 32);
    else if (c >= 'a' && c <= 'z')
      printf("%c\n", c - 32);
    else
      printf("Not a letter, try again!\n");
  }
}
