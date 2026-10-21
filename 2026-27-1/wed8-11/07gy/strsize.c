// Mit ír ki az alábbi program? Miért?

#include <stdio.h>
#include <string.h>

int main() {
  const char str[] = "Hello";

  // A "zu"-ba garantáltan belefér a sizeof
  // kifejezés értéke, és az strlen
  // visszatérési értéke.
  printf("%zu\n", sizeof(str));
  printf("%zu\n", strlen(str));
}
