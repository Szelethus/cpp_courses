#include <iostream>

int main() {
  std::cout << "Please provide a character to encode!\n";

  char input;
  std::cin >> input;

  std::string from = "aeiou";
  std::string to   = "eioua";

  bool isVowel = false;
  for (int i = 0; i < from.size(); ++i) {
    if (input == from[i]) {
      isVowel = true;
      break;
    }
  }

  if (!isVowel) {
    std::cout << "INCORRECT USAGE: Please provide a vowel!\n";
    return 1;
  }

  for (int i = 0; i < from.size(); ++i) {
    if (input == from[i]) {
      input = to[i];
      break;
    }
  }

  std::cout << "Your encoded character: " << input << '\n';
  return 0;
}
