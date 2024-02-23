#include <iostream>

char encode(char c) {
  std::string from = "aeiou";
  std::string to =   "eioua";
  for (int i = 0; i < from.size(); ++i) {
    if (c == from[i]) {
      return to[i];
    }
  }
  return c;
}

std::string read() {
  std::string c;
  while (true) {
    std::string tmp;
    std::cin >> tmp;
    if (std::cin.fail())
      return c;
    c += tmp + ' ';
  }
}

int main() {
  std::cout << "read: \n";
  std::string c = read();

  for (int i = 0; i < c.size(); ++i)
    c[i] = encode(c[i]);

  std::cout << c;
}
