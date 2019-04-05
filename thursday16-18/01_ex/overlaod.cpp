#include <iostream>

struct Vec {
  int a, b;
};

int operator*(const Vec &v1, const Vec &v2) {
  return v1.a * v2.a + v1.b * v2.b;
}

std::ostream& operator<<(std::ostream &out, const Vec &v) {
  out << v.a << ' ' << v.b;
  return out;
}

int main() {
  Vec v1;
  Vec v2;

  v1.a = 6;
  v1.b = 3;
  v2.a = 2;
  v2.b = 9;

  std::cout << v1 << '\n';
  std::cout << v1 * v2 << '\n'; 
}
