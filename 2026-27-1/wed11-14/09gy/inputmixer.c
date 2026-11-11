#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void wordcount() {
  char filename[1024];
  printf("Please provide a filename: ");
  if (NULL == fgets(filename,
                    sizeof(filename),
                    stdin)) {
    printf("Failed to get filename!\n");
    return;
  }

  filename[strcspn(filename, "\n")] = '\0';

  FILE *f = fopen(filename, "r");
  if (!f) {
    printf("Failed to open input file!\n");
    return;
  }

  int ch;
  int count = 0;
  bool inWord = false;
  while (EOF != (ch = getc(f))) {
    if (isspace(ch)) {
      inWord = false;
    } else {
      if (!inWord)
        ++count;
      inWord = true;
    }
  }

  printf("Word count: %d\n", count);
  fclose(f);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage:\n"
           "%s wc\n"
           "%s encode\n",
           argv[0], argv[0]);
    return 1;
  }

  if (0 == strcmp(argv[1], "wc")) {
    wordcount();
  }
}
