#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return -1;
  }

  FILE *f = fopen(argv[1], "r");
  if (!f) {
    printf("Failed to open '%s'\n", argv[1]);
    return -1;
  }

  char str[1024];

  if (NULL == fgets(str, sizeof(str), f)) {
    printf("Failed to read from fgets");
    return -1;
  }

  str[strcspn(str, "\n")] = '\0';

  char *end;

  errno = 0;
  long val = strtol(str, &end, 10);

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

  printf("Converted int: %ld\n", val);
}
