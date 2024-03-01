#include <iostream>

int main() {
  std::cout << "Please provide a character: ";

  char c;
  std::cin >> c;

  switch (c) {
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
    std::cout << "Vowel!\n";
    break;
  default:
    std::cout << "Not a vowel!\n";
    break;
  }
}
