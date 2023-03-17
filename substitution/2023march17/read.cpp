#include <iostream>

std::string readName() {
  std::string name;
  std::cout << "Please provide your name: ";
  std::cin >> name;

  return name;
}
