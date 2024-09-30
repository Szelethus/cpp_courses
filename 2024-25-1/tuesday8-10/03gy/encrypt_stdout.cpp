#include <iostream>

char encode(char c) {
  std::string from = "aeiou";
  std::string to   = "eioua";

  for (int i = 0; i < sizeof(from) / sizeof(from[0]); ++i) {
    if (c == from[i]) {
      return to[i];
    }
  }
  return c;
}

int main() {
  std::string str;
  std::cout << "Please provide your input:\n";

  std::string tmp;
  while (std::cin >> tmp) {
    str += tmp + ' ';
  }

  for (int i = 0; i < str.size(); ++i) {
    str[i] = encode(str[i]);
  }

  std::cout << "Your encoded input:\n" << str << '\n';
}
