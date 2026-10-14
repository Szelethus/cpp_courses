#include <stdio.h>
#include <string.h>

int main() {
  char buffer[6];

  // sizeof(char) == sizeof(buffer[0]) == 1
  fgets(buffer, sizeof(buffer), stdin);
  buffer[strcspn(buffer, "\n")] = '\0';

  fprintf(stdout, "%s\n", buffer);
}
