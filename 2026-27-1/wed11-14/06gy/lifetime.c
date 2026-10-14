#include <stdio.h>

int *getPtr() {
  int k;
  return &k;
}

int main() {
  int *ptr = getPtr();

  printf("%d\n", *ptr);
}
