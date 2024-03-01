#include <iostream>
#include <fstream>

char encode(char c) {
  std::string from = "aeiou";
  std::string to =   "eioua";

  for (int i = 0; i < from.size(); i++) {
    if (c == from[i])
      return to[i];
  }
  return c;
}

int main() {
  std::ifstream ifs("input.txt");
  if (ifs.fail()) {
    std::cout << "Failed to open file!\n";
    return -1;
  }

  std::string str;

  while (true) {
    std::string tmp;
    ifs >> tmp;
    if (ifs.fail())
      break;
    str += tmp + ' ';
  }

  for (int i = 0; i < str.size(); ++i) {
    str[i] = encode(str[i]);
  }

  std::cout << "Your encoded character: " << str << '\n';
}
