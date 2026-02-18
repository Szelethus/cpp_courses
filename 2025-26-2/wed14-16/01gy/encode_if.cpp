#include <iostream>

int main() {
  std::cout << "Please provide a character: ";

  char c;
  std::cin >> c;

  if (c == 'a') {
    c = 'e';
  }
  else if (c == 'e') {
    c = 'i';
  }
  else if (c == 'i') {
    c = 'o';
  }
  else if (c == 'o') {
    c = 'u';
  }
  else if (c == 'u') {
    c = 'a';
  }
  else {
    std::cout << "Not a vowel\n";
  }

  std::cout << "Your character: " << c << '\n';
}
