#include <iostream>

int main() {
  std::string from = "aeiou";
  std::string to =   "eioua";

  std::cout << "Please provide your data to encrypt:\n";
  std::string data;

  while (std::cin) {
    std::string tmp;
    std::cin >> tmp;
    data += tmp;
  }
  
  for (int i = 0; i < data.size(); ++i) {
    for (int j = 0; j < from.size(); ++j) {
      if (data[i] == from[j]) {
        data[i] = to[j];
        break;
      }
    }
  }

  std::cout << data << '\n';
}
