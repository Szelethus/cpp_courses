#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
  for (int i = 0; i < argc; ++i) {
    printf("%s\n", argv[i]);
  }

  for (int i = 1; i < argc; ++i) {
    char *end;

    errno = 0;
    int val = strtol(argv[i], &end, 10);

    if (end == argv[i]) {
      printf("Not a number!\n");
      continue;
    }

    if (*end != '\0') {
      printf("Trailing!\n");
      continue;
    }

    if (errno == ERANGE) {
      printf("Wrong size!\n");
      continue;
    }

    printf("%d\n", val);
  }
}
