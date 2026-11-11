#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

FILE *openPromptedFile(const char *mode) {
  char filename[1024];
  printf("Add filename: ");
  if (NULL == fgets(filename,
              sizeof(filename),
              stdin)) {
    printf("Failed to retrieve "
           "filename!\n");
    return NULL;
  }
  filename[strcspn(filename, "\n")] = '\0';

  return fopen(filename, mode);
}

void wordcount() {
  FILE *f = openPromptedFile("r");

  if (!f) {
    printf("Failed to open file!\n");
    return;
  }

  int ch;
  bool inWord = false;
  int count = 0;

  while (EOF != (ch = fgetc(f))) {
    if (isspace(ch)) {
      inWord = false;
    } else {
      if (inWord == false) {
        ++count;
      }
      inWord = true;
    }
  }

  printf("File has %d words\n", count);

  fclose(f);
}

char encode(char c) {
  const char from[] = {'a', 'e', 'i', 'o', 'u'};
  const char to[]   = {'e', 'i', 'o', 'u', 'a'};

  for (int i = 0; i < sizeof(from); ++i) {
    if (c == from[i])
      return to[i];
  }

  return c;
}

void encodeString(char *str) {
  for (int i = 0; str[i] != '\0'; ++i) {
    str[i] = encode(str[i]);
  }
}

void encodeFile() {
  FILE *inf = openPromptedFile("r");
  if (!inf) {
    printf("Failed to open input file!\n");
    return;
  }

  FILE *outf = openPromptedFile("w");
  if (!outf) {
    fclose(inf);
    printf("Failed to open output file!\n");
    return;
  }

  char buffer[16];

  while (NULL != fgets(buffer,
                       sizeof(buffer),
                       inf)) {
    encodeString(buffer);
    fprintf(outf, "%s", buffer);
  }

  fclose(inf);
  fclose(outf);
}


int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage:\n");
    printf("%s wc\n", argv[0]);
    printf("%s encode\n", argv[0]);
    return 1;
  }

  if (0 == strcmp(argv[1], "wc")) {
    wordcount();
  } else if (0 == strcmp(argv[1], "encode")) {
    encodeFile();
  }
}
