#include <stdio.h>

int main() {
  int ch;

  printf("EOF: %d\n", EOF);

  while (EOF != (ch = getchar())) {
    fprintf(stdout, "%c", ch);
  }
}
