#include <stdio.h>

// forward declaration
void convertLetter(char c);

int main() {
  char c;
  do {
    c = getchar();
    getchar();
    convertLetter(c);
  } while (c != 0);
}

void convertLetter(char c) {
  if (c >= 'A' && c <= 'Z')
    printf("%c\n", c + 32);
  else if (c >= 'a' && c <= 'z')
    printf("%c\n", c - 32);
  else
    printf("Not a letter, try again!\n");
}
