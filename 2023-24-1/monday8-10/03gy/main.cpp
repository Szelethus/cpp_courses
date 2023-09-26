#include <iostream>
#include <fstream>

int main() {
  std::string str;
  while (std::cin) {
    std::cin >> str;
    std::cout << str << '\n';
  }
  std::cout << "fail?" << (std::cin.fail()) << '\n';
  std::ifstream f("alma.txt");
  int i;
  f >> i;
  std::cout << i << '\n';
  while (f) {
    std::getline(f, str);
    std::cout << str << '\n';
  }
}
