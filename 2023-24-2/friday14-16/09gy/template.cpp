#include <iostream>

template <class T>
void swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <int N>
void printN() {
  std::cout << N << '\n';
}

int main() {
  int c = 5, d = 8;
  swap(c, d);

  std::string str1 = "Hello", str2 = "World";
  ::swap(str1, str2);

  printN<100>();
}
