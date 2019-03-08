#include <iostream>

struct A {
  int a;
  double c;
  int b;
};

int main() {
  std::cout << sizeof(int) << '\n';
  
  std::cout << sizeof(double) << '\n';
  std::cout << sizeof(A) << '\n';
}
