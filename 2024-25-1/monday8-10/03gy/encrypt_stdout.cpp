#include <iostream>

char encode(char c) {
  std::string from = "aeiou";
  std::string to   = "eioua";

  for (int i = 0; i < from.size(); ++i) {
    if (c == from[i]) {
      return to[i];
    }
  }

  return c;
}

int main() {
  std::cout << "Please provide your data: \n";

  std::string input;

  std::string tmp;
  while(std::cin >> tmp) {
    input += tmp + ' ';
  }

  for (int i = 0; i < input.size(); ++i) {
    input[i] = encode(input[i]);
  }

  std::cout << "Your encoded input:\n" << input << '\n';
}
