#include <stdio.h>

char encode(char c) {
  const char from[] = {'a', 'e', 'i', 'o', 'u'};
  const char to[]   = {'e', 'i', 'o', 'u', 'a'};

  for (int i = 0; i < sizeof(from); ++i) {
    if (c == from[i])
      return to[i];
  }

  return c;
}

void printEncodedWord(const char *input) {
  for (int i = 0; input[i] != '\0'; ++i) {
    putc(encode(input[i]), stdout);
  }
  putc('\n', stdout);
}

int main(int argc, char **argv) {
  char buffer[1024];

  if (argc == 1) {
    printf("Usage: %s <word1> "
           "... <wordn>\n", argv[0]);
    return -1;
  }

  for (int i = 1; i < argc; ++i) {
    printEncodedWord(argv[i]);
  }

}
