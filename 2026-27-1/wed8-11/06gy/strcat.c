#include <stdio.h>
#include <string.h>

int main() {
  char str1[1024] = "Hello";
  char str2[] = " World!";

  strcat(str1, str2);

  printf("%s\n", str1);
}
