#include <iostream>

int main() {
  char c;
  std::cout << "Please provide a character: ";
  std::cin >> c;

  if (c == 'a' || c == 'e' || c == 'i' || c == 'o'
      || c == 'u') {
    std::cout << "Vowel\n";
  }
  else {
    std::cout << "non-vowel\n";
  }

}
