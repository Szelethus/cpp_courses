#include <iostream>
#include <fstream>

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
  std::ifstream ifs("in put.txt");
  if (ifs.fail()) {
    std::cout << "Failed to open!\n";
    return -1;
  }

  std::string word;

  std::string tmp;
  std::getline(ifs, tmp);
  while (!ifs.fail()) {
    word += tmp + '\n';
    std::getline(ifs, tmp);
  }

  for (int i = 0; i < word.size(); ++i) {
    word[i] = encode(word[i]);
  }

  std::cout << "Your encoded input:\n" << word << '\n';
}
