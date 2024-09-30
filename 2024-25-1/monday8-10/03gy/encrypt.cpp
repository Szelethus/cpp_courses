#include <iostream>
#include <fstream>

int main() {
  std::string from = "aeiou";
  std::string to =   "eioua";

  std::ifstream ifs("alma.txt");

  int n;
  ifs >> n;
  ifs.ignore();

  std::string str;
  while (ifs) {
    std::string tmp;
    std::getline(ifs, tmp);
    str += tmp + '\n';
  }

  for (int i = 0; i < str.size(); ++i) {
    for (int j = 0; j < from.size(); ++j) {
      if (str[i] == from[j]) {
        str[i] = to[j];
        break;
      }
    }
  }

  std::cout << str;
}
