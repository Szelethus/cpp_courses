#include <stdio.h>

int main() {
  int *ptr = NULL;
  printf("%p\n", ptr);
  if (ptr == NULL) {
    printf("Doesn't point to anything!\n");
  }
}
