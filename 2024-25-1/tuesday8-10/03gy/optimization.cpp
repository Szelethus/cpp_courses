#include <iostream>

bool value(int l, int r) {
  if (l < r)
    return true;

  l += 1;
  return l > r;
}

bool ref(int *const l, int *const r) {
  if (*l < *r)
    return true;

  *l += 1;
  return *l > *r;
}

int main() {
  int a = 5;
  int b = 5;
  std::cout << value(a, b) << ' ' << ref(&a, &a) << '\n';
}
