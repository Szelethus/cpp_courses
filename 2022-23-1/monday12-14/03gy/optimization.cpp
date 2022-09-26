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

//int &incr(int &a) {
//  a += 1;
//  return a;
//}

int main() {
  int a = 3;
  int b = 5;
  std::cout << value(a, b) << ' ' << ref(a, a) << '\n';
  //int &ref = incr(b);
  //ref += 1;
  //std::cout << ref << '\n';
}
