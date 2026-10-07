#include <stdio.h>
#include <string.h>

int main(void) {
  char buffer[6];

  fgets(buffer, sizeof(buffer), stdin);

  printf("%s\n", buffer);
  return 0;
}
