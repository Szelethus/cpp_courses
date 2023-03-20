#include <iostream>
#include <fstream>

char encode(char c) {
  std::string from = "aeiou";
  std::string to = "eioua";

  for (int i = 0; i < from.size(); ++i) {
    if (c == from[i])
      return to[i];
  }
  return c;
}

int main() {
  std::ifstream ifs("input.txt");
  std::string name;
  ifs >> name;

  for (int i = 0; i < name.size(); ++i) {
    name[i] = encode(name[i]);
  }

  std::cout << "result: " << name << '\n';
}
