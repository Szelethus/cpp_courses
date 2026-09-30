#include <stdio.h>

int main() {
  int k = 6;

  int *ptr;

  ptr = &k;
  *ptr = 8;

  printf("%d\n", k);
  printf("%d\n", *ptr);

  printf("%p\n", &k);
  printf("%p\n", ptr);
}
