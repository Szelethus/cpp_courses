#include <iostream>

struct A {
  int a;
  long c;
  int b;
};

int main() {
  std::cout << sizeof(int) << '\n'; 
  std::cout << sizeof(long) << '\n'; 
  std::cout << sizeof(A) << '\n'; 
}
