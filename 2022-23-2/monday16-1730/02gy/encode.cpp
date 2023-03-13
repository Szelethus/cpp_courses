#include <iostream>

char encode(char c) {
  std::string from = "aeiou";
  std::string to = "eioua";

  for (int i = 0; i < from.size(); ++i) {
    if (from[i] == c) {
      c = to[i];
      break;
    }
  }
  return c;
}

int main() {
  std::string input;
  std::cout << "Please provide a character to encode: ";
  std::cin >> input;

  std::string from = "aeiou";
  std::string to = "eioua";

  for (int i = 0; i < input.size(); ++i) {
    input[i] = encode(input[i]);
  }
  
  std::cout << "Encoded: " << input << '\n';
}
