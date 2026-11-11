#include <stdio.h>

int isEven(int *ptr, int size) {
  int count = 0;
  for (int i = 0; i < size; ++i) {
    if (ptr[i] % 2 != 0)
      continue;

    printf("Even number found!: %d\n", ptr[i]);
    ++count;
  }
  return count;
}

void file() {
  FILE *f = fopen("a.txt", "r");
  FILE *f2 = fopen("b.txt", "r");

  if (!f) {
    printf("Failed to open file!\n");
    return;
  }

  fclose(f);
  fclose(f2);
}

