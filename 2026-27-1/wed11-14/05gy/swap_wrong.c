#include <stdio.h>

void swap(int *const a, int *const b) {
  int *tmp = a;
  a = b;
  b = tmp;
}

int main() {
  int c = 5, d = 8;

  swap(&c, &d);

  printf("c=%d, d=%d\n",
         c, d);
}
