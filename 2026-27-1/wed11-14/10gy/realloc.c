#include <stdio.h>
#include <stdlib.h>

int main() {
  int *ptr = malloc(4 * sizeof(int));
  if (!ptr)
    return 1;

  {
    int *newPtr = realloc(ptr, 8 * sizeof(int));
    if (!newPtr) {
      printf("Failed to realloc!\n");
      free(ptr);
      return 1;
    }
    ptr = newPtr;
  }

  free(ptr);
}
