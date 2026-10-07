#include <stdio.h>

int sum(int *p, int size) {
  int ret = 0;

  for (int i = 0; i < size; ++i) {
    ret = ret + p[i];
  }

  return ret;
}

int main() {
  int t[] = {1,2,3};
  
  int size = sizeof(t) / sizeof(t[0]);

  int s = sum(t,
              sizeof(t) / sizeof(t[0]));

  printf("%d\n", s);
}
