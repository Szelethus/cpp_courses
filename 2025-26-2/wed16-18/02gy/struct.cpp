#include <iostream>

struct MyStruct {
  short a;
  int c;
  short b;
};

int main() {
  std::cout << sizeof(char) << '\n';
  std::cout << sizeof(bool) << '\n';

  std::cout << sizeof(short) << '\n';
  std::cout << sizeof(int) << '\n';

  std::cout << sizeof(MyStruct) << '\n';
}
