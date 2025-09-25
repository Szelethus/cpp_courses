#include <iostream>

int main() {
  std::string c;
  std::cout << "Please provide your string: ";
  std::cin >> c;

  char encoded;

  switch (c) {
  case 'a':
    encoded = 'e';
    break;
  case 'e':
    encoded = 'i';
    break;
  case 'i':
    encoded = 'o';
    break;
  case 'o':
    encoded = 'u';
    break;
  case 'u':
    encoded = 'a';
    break;
  default:
    encoded = c;
  }
  std::cout << "Your encoded characted is: " << encoded << '\n';
}
