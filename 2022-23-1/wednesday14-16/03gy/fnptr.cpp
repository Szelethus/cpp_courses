#include <iostream>

//int sum(int *p, int size) {
//  int sum = 0;
//  for (int i = 0; i < size; ++i)
//    sum += p[i];
//  return sum;
//}
//
//int prod(int *p, int size) {
//  int prod = 1;
//  for (int i = 0; i < size; ++i)
//    prod *= p[i];
//  return prod;
//}

int add(int l, int r) { return l + r; }
int mul(int l, int r) { return l * r; }

int accumulate(int *p, int size, int unit, int (*op)(int, int)) {
  int result = unit;
  for (int i = 0; i < size; ++i)
    result = (*op)(result, p[i]);
  return result;
}

int main() {
  int t[] = {1,2,3,4,5};
  //std::cout << sum(t, sizeof(t)/sizeof(t[0])) << '\n';
  //std::cout << prod(t, sizeof(t)/sizeof(t[0])) << '\n';
  std::cout << accumulate(t, sizeof(t)/sizeof(t[0]), 0, &add) << '\n';
  std::cout << accumulate(t, sizeof(t)/sizeof(t[0]), 1, &mul) << '\n';
}
