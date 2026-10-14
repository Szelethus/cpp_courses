#include <stdio.h>

int *getPtr() {
  int c;
  return &c;
}

int main() {
  int *ptr = getPtr();
  *ptr = 6;
  printf("%d\n", *ptr);
}
