#include <stdio.h>

int main() {
  char filename[] = "alma.txt";

  FILE *f = fopen(filename, "r");
  if (NULL == f) {
    printf("Failed to open file '%s'\n",
           filename);
    return -1;
  }

  char buffer[1024];
  fgets(buffer, sizeof(buffer), f);

  printf("File contents: %s\n", buffer);

  fclose(f);
}
