#include <stdio.h>

int main() {
  int x = 7;

  {
    printf("%d\n", x);
    int x = 8;
    printf("%d\n", x);
  }
}
