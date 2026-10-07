#include <stdio.h>

int x = 3;

int main() {
  int x = 5;

  {
    int x = 10;

    printf("%d\n", x);
  }
}
