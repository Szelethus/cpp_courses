#include <iostream>

//int prod(int *t, int size) {
//  int prod = 1;
//  for (int i = 0; i < size; ++i) {
//    prod *= t[i];
//  }
//  return prod;
//}
//
//int sum(int *t, int size) {
//  int sum = 0;
//  for (int i = 0; i < size; ++i) {
//    sum += t[i];
//  }
//  return sum;
//}

int accumulate(int *t, int size, int (*op)(int, int), int start) {
  int sum = start;
  for (int i = 0; i < size; ++i) {
    sum = (*op)(sum, t[i]);
  }
  return sum;
}

int add(int l, int r) { return l + r; }
int mul(int l, int r) { return l * r; }

int main() {
  int t[] = {1, 2, 3, 4, 5};
  //std::cout << sum(t, sizeof(t) / sizeof(t[0])) << '\n';
  //std::cout << prod(t, sizeof(t) / sizeof(t[0])) << '\n';
  std::cout << accumulate(t, sizeof(t) / sizeof(t[0]), &add, 0) << '\n';
  std::cout << accumulate(t, sizeof(t) / sizeof(t[0]), &mul, 1) << '\n';
}
