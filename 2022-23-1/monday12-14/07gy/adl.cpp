#include <iostream>

int main() {
  std::cout << "Hello World!\n";
  std::operator<<(std::cout, "Hello World!\n");
  std::cout.operator<<(std::endl);
}
