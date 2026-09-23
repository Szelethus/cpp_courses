#include <endian.h>
#include <stdio.h>

int addTwo(int i) {
  return i + 2;
}

int main() {
  int i = 0;
  printf("%d\n", addTwo(i));
}
