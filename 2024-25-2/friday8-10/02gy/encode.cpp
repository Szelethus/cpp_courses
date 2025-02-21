#include <fstream>
#include <iostream>

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
  std::string str;

  std::ifstream ifs("input.txt");
  if (ifs.fail())
    return -1;
  
  std::string tmp;
  while (std::getline(ifs, tmp)) {
    str += tmp;
  }

  for (int i = 0; i < str.size(); ++i) {
    str[i] = encode(str[i]);
  }

  std::cout << "Your encoded character: " << str << '\n';
}
