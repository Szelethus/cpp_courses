#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void usage() {
  printf("Usage\n");
  printf("wc -> word counter\n");
  printf("upper -> lexicographic comparison\n");
}

FILE *openPromptedFile(const char *mode) {
  char filename[256];
  if (NULL == fgets(filename, sizeof(filename), stdin))
    return NULL;

  filename[strcspn(filename, "\n")] = '\0';
  return fopen(filename, mode);
}

void charcount() {
  FILE *f = openPromptedFile("r");
  if (!f) {
    printf("failed to open file\n");
    usage();
    return;
  }

  int c;
  int count = 0;
  while (EOF != (c = fgetc(f))) {
    ++count;
  }

  printf("Words: %d\n", count);
}

void upper() {
  FILE *input = openPromptedFile("r");
  FILE *output = openPromptedFile("w");

  if (!input) {
    printf("failed to open input file\n");
    usage();
    return;
  }
  if (!output) {
    printf("failed to open output file\n");
    usage();
    return;
  }

  int ch;
  while (EOF != (ch = fgetc(input))) {
    if (EOF == fputc(toupper(ch), output)) {
      printf("Error while writing\n");
      return;
    }
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    usage();
    return 1;
  }

  if (0 == strcmp(argv[1], "wc")) {
    charcount();
  } else if (0 == strcmp(argv[1], "upper")) {
    upper();
  }
}
