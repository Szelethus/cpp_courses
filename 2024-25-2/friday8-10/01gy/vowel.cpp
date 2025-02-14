#include <iostream>

int main() {
  char c;
  std::cout << "Please provide a character: ";
  std::cin >> c;

  switch(c) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      std::cout << "Vowel\n";
      break;
    default:
      std::cout << "non-vowel\n";
      break;
  }
}
