#include <iostream>

char encode(char c) {
  std::string from = "aeiou";
  std::string to   = "eioua";

  for (int i = 0; i < from.size(); ++i) {
    if (c == from[i])
      return to[i];
  }

  return c;
}

int main() {
  std::cout << "Please provide your input: ";

  std::string word;

  std::string tmp;
  std::cin >> tmp;
  while (!std::cin.fail()) {
    word += tmp + ' ';
    std::cin >> tmp;
  }

  for (int i = 0; i < word.size(); ++i) {
    word[i] = encode(word[i]);
  }

  std::cout << "Your encoded input:\n" << word << '\n';
}
