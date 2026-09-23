#include <stdio.h>

int main() {
  int date = 19991201;
  int year = date / 10000;
  int month = date / 100 % 100;
  int day = date % 100;

  printf("%d, %d, %d\n", year, month, day);
}
