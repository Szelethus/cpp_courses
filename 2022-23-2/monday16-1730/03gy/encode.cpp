#include <iostream>
#include <fstream>

char encode(char c) {
  std::string from = "aeiou";
  std::string to = "eioua";

  for (int i = 0; i < from.size(); ++i) {
    if (c == from[i]) {
      return to[i];
    }
  }

  return c;
}

int main() {
  std::ifstream ifs("alma.txt");
  if (ifs.fail()) {
    std::cout << "Failed to open input.txt!\n";
    return 1;
  }

  std::string result;

  while (true) {
    std::string word;
    ifs >> word;

    if (ifs.fail())
      break;

    for (int i = 0; i < word.size(); ++i) {
      word[i] = encode(word[i]);
    }

    result += word + ' ';
  }

  std::cout << "result: " << result << '\n';
}
