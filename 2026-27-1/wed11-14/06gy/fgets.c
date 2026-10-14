#include <stdio.h>
#include <string.h>

int main() {
  char buffer[6];

  fgets(buffer, sizeof(buffer), stdin);
  buffer[strcspn(buffer, "\n")] = '\0';

  printf("%s\n", buffer);
}
