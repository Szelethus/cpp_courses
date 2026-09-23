#include <ctype.h>
#include <stdio.h>

int isUpper(char c) {
  return c >= 'A' && c <= 'Z';
}

int isLower(char c) {
  return c >= 'a' && c <= 'z';
}

int main() {
  char c;
  for (int i = 0; i < 3; ++i) {
    c = getchar();
    getchar();
    if (isUpper(c))
      printf("%c\n", tolower(c));
    else if (isLower(c))
      printf("%c\n", toupper(c));
    else
      printf("Not a letter, try again!\n");
  }
}
