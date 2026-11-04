#include <stdio.h>

char encode(char c) {
  char from[] = {'a', 'e', 'i', 'o', 'u'};
  char to[]   = {'e', 'i', 'o', 'u', 'a'};

  for (int i = 0; i < 5; ++i) {
    if (c == from[i])
      return to[i];
  }
  return c;
}

int main(int argc, char **argv) {
  if (argc != 2)
    return -1;

  FILE *f = fopen(argv[1], "r");
  if (!f)
    return -1;

  char buf[4];

  printf("Your encoded characters: ");
  while (NULL != fgets(buf, sizeof(buf), f)) {
    for (int i = 0; buf[i] != '\0'; ++i) {
      putc(encode(buf[i]), stdout);
    }
  }
  fclose(f);
}
