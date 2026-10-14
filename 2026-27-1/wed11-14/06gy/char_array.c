#include <stdio.h>

int main() {
  char str1[] = {'H', 'e', 'l', 'l', 'o'};
  char str2[] = "Hello";

  printf("%lu\n", sizeof(str1));
  printf("%lu\n", sizeof(str2));

  // Hibás! %s-el csak null-terminált sztringeket
  // lehet kiírni
  printf("%s\n", str1);
  printf("%s\n", str2);
}
