#include <iostream>

bool value(int l, int r) {
  if (l < r)
    return true;

  l += 1;
  return l > r;
}

bool ref(int &l, int &r) {
  if (l < r)
    return true;

  l += 1;
  return l > r;
}

int main() {
  int a = 3;
  int b = 5;
  std::cout << value(a, b) << ' ' << ref(a, b) << '\n';
}
