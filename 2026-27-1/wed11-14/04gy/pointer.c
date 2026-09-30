#include <stdio.h>

int main() {
  int k = 8;

  int *ptr;

  ptr = &k;

  *ptr = 10;

  printf("%d\n", k);
  printf("%d\n", *ptr);

  printf("%p\n", &k);
  printf("%p\n", ptr);
}
