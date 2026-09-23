#include <stdio.h>

int main() {
  char c;
  for (int i = 0; i < 3; ++i) {
    scanf(" %c", &c);
    if (c >= 'A' && c <= 'Z')
      printf("%c\n", c + 32);
    else if (c >= 'a' && c <= 'z')
      printf("%c\n", c - 32);
    else
      printf("Not a letter, try again!\n");
  }
}
