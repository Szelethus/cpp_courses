#include <ctype.h>
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
  if (isupper(c))
    printf("%c\n", tolower(c));
  else if (islower(c))
    printf("%c\n", toupper(c));
  else
    printf("Not a letter, try again!\n");
}
