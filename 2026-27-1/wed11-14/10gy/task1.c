#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *ptr = malloc(20 * sizeof(char));
  if (!ptr)
    return 1;

  scanf("%20s", ptr);

  int size = strlen(ptr) + 1;

  char *ptr2 = malloc(size * sizeof(char));
  if (!ptr2) {
    free(ptr);
    return 1;
  } 

  strcpy(ptr2, ptr);

  free(ptr);
  free(ptr2);
}
