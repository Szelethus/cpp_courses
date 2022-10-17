#include <iostream>

int main() {
  std::operator<<(std::cout, "Hello World!\n");
  std::cout.operator<<(std::endl);
}
