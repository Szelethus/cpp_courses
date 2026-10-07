#include <stdio.h>

int sum(int *p, int size) {
  int res = 0;
  for (int i = 0; i < size; ++i) {
    res = res + p[i];
  }
  return res;
}

int main() {
  int t[] = {1,2,3};

  int s = sum(t,
              sizeof(t) / sizeof(t[0]));
  printf("sum: %d\n", s);
}
