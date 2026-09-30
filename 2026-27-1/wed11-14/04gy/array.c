#include <stdio.h>

void printArray(int *p, int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d\n", p[i]);
  }
}

int main() {
  int t[5];

  t[0] = 1;
  t[1] = 2;
  t[2] = 3;
  t[3] = 4;
  t[4] = 5;

  printArray(t, sizeof(t) / sizeof(t[0]));
}
