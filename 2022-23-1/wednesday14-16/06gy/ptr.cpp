#include <iostream>



// [begin, end)
int sum(int *begin, int *end) {
  int sum = 0;
  for (; begin != end; ++begin) {
    sum += *begin;
  }
  return sum;
}


int main() {
  int arr[] = {15, 7, 5, 4};

  int *start = arr;
  int *end = arr + 4;

  std::cout << sum(start, end) << '\n';
  std::cout << sum(start + 1, end - 1) << '\n';
}

// Iterátor:
// * Léptetni: ++, --, +, -
// * Össze lehet hasonlítani: ==, !=
// * Adott elem lekérdezése: *
