#include <stdio.h>

int main() {
  int ch;

  while ((ch = getchar()) != EOF) {
    if (ch == '\n')
      printf("Newline\n");
  }
}
