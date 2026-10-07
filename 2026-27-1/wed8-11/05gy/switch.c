#include <stdio.h>

int main() {
  int day_of_week = 6;
  switch (day_of_week) {
  default: printf("Undefined\n");
  case 2: printf("Monday\n");
  case 3: printf("Tuesday\n");
  case 4: printf("Wednesday\n");
  case 5: printf("Thursday\n");
  case 6: printf("Friday\n");
  case 1:
  case 7: printf("Weekend\n");
  }
}
