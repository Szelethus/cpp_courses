#include <iostream>

char encode(char c) {
  std::string from = "aeiou";
  std::string to = "eioua";

  for (int j = 0; j < from.size(); ++j) {
    if (c == from[j]) {
      c = to[j];
      break;
    }
  }
  
  return c;
}

int main() {
  std::cout << "Please provide a character to encode!\n";

  std::string input;
  std::cin >> input;

  for (int i = 0; i < input.size(); ++i) {
    input[i] = encode(input[i]);
  }

  std::cout << "Your encoded character: " << input << '\n';
  return 0;
}
