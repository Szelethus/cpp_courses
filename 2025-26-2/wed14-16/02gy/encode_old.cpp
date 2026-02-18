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
  std::cout << "Please provide an input: ";

  std::string str;
  std::string tmp;

  std::cin >> tmp;
  while (true) {
    str += tmp;
    std::cin >> tmp;
  }

  for (int i = 0; i < str.size(); ++i) {
    str[i] = encode(str[i]);
  }

  std::cout << "Your encoded input is: " << str << '\n';
}
