#include <iostream>

inline int times2(int i) { return i * 2; }

int main() {
  std::cout << times2(5) * times2(10) << '\n';
}
