#include <stdio.h>

int main(int argc, char **argv) {
  char filename[] = "alma.txt";
  FILE *f = fopen(filename, "r");

  if (f == NULL) {
    printf("Failed to open file '%s'\n",
           filename); 
    return -1;
  }

  char buffer[1024];
  
  if (NULL == fgets(buffer,
                    sizeof(buffer),
                    f)) {
    printf("Failed to read file!\n");
  }

  printf("File contents:\n%s", buffer);

  fclose(f);
}
