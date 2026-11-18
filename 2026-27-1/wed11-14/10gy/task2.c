#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *getWordFromStdin() {
  int size = 1;
  char *buffer = malloc(size * sizeof(char));
  int ch;

  // Mi van a whitespace-el kezdünk?
  // Mi van ha több whitespace választ el két szót?
  while (EOF != (ch = getchar()) && !isspace(ch)) {
    buffer[size - 1] = ch;

    // Buffer növelése
    ++size;
    char *newBuf = realloc(buffer, size * sizeof(char));
    if (!newBuf) {
      printf("Failed to realloc!\n");
      free(buffer);
      return NULL;
    }
    buffer = newBuf;
  }

  buffer[size - 1] = '\0';
  return buffer;
}

int main() {
  char *words[5];

  for (int i = 0;
       i < sizeof(words) / sizeof(words[0]);
       ++i) {
    // Ne feledjük, hogy a getWordFromStdin
    // malloc-al létrehozott változót
    // ad vissza, fel kell majd szabadítani!
    words[i] = getWordFromStdin();
  }

  for (int i = sizeof(words) / sizeof(words[0]) - 1;
       i >= 0;
       --i) {
    printf("%s\n", words[i]);
    free(words[i]);
  }
}
