#include <iostream>

/*
struct Vec {
  int a, b;

private:
  Vec &operator=(const Vec &) {
    return *this;
  }
};
*/

template <typename T>
void swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

int main() {
  int a = 5, b = 7;
  double d1 = 6.0, d2 = 5.3;
  //Vec a1, a2;

  swap<double>(d1, d2);

  swap<int>(a, b);

  //swap<Vec>(a1, a2);

  std::cout << a << ' ' << b << '\n';
}
