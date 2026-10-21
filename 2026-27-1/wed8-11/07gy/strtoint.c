#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
  char str[] = "12327893465234648346237896423784623786423786238";

  char *end;

  errno = 0;
  int val = strtol(str, &end, 10);

  if (end == str) {
    printf("Not a number!\n");
    return 1;
  }

  if (*end != '\0') {
    printf("Trailing string!\n");
    return 1;
  }

  if (errno == ERANGE) {
    printf("Number is of wrong size!\n");
    return 1;
  }

  printf("Converted int: %d\n", val);
}
