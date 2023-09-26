#include <iostream>

int main() {
  std::string from = "aeiou";
  std::string to =   "eioua";

  std::string str;
  std::cout << "Please provide your data: \n";
  while (std::cin) {
    std::string tmp;
    std::cin >> tmp;
    str += tmp;
  }

  for (int i = 0; i < str.size(); ++i) {
    for (int j = 0; j < from.size(); ++j) {
      if (str[i] == from[j]) {
        str[i] = to[j];
        break;
      }
    }
  }

  std::cout << str << '\n';
}
