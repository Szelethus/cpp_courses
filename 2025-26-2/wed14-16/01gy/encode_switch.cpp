#include <iostream>

int main() {
  std::cout << "Please provide a character: ";

  char c;
  std::cin >> c;

  switch (c) {
  case 'a':
    c = 'e';
    break;
  case 'e':
    c = 'i';
    break;
  case 'i':
    c = 'o';
    break;
  case 'o':
    c = 'u';
    break;
  case 'u':
    c = 'a';
    break;
  default:
    std::cout << "Not a vowel\n";
    break;
  }

  std::cout << "Your character: " << c << '\n';
}
