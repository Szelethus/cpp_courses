#include <ctype.h>
#include <stdio.h>

int main() {
  char c;
  for (int i = 0; i < 3; ++i) {
    scanf(" %c", &c);
    if (isupper(c))
      printf("%c\n", tolower(c));
    else if (islower(c))
      printf("%c\n", toupper(c));
    else
      printf("Not a letter!\n");
  }
}
