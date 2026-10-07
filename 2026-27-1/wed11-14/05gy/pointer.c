#include <stdio.h>

int main() {
  int k = 5;
  int *ptr = &k;

  *ptr = 10;

  printf("%d\n", k);
}
