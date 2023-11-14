#include <iostream>

int accumulate(int *t, int size, int op(int, int), int start) {
  int sum = start;
  for (int i = 0; i < size; ++i) {
    sum = op(sum, t[i]);
  }
  return sum;
}

int add(int l, int r) { return l + r; }
int mul(int l, int r) { return l * r; }

int main() {
  int t[] = {1, 2, 3, 4, 5};
  std::cout << accumulate(t, sizeof(t) / sizeof(t[0]), add, 0) << '\n';
  std::cout << accumulate(t, sizeof(t) / sizeof(t[0]), mul, 1) << '\n';
}
