#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
  const char str[] = "1223478574682374678325482364583254823765423768452376542376854237685423763";

  char *end;
  errno = 0;
  long i = strtol(str, &end, 10);

  if (end == str) {
    printf("Not a number!\n");
    return 1;
  }

  if (*end != '\0') {
    printf("Trailing string!\n");
    return 1;
  }

  if (errno == ERANGE) {
    printf("Number is of inappropriate "
           "size!\n");
    return 1;
  }

  printf("%ld\n", i);
}
