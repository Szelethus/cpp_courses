#include <iostream>
#include <fstream>

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
  std::string str;
  std::ifstream ifs("input.txt");
  if (ifs.fail()) {
    std::cout << "Error opening file!\n";
    return -1;
  }

  int N;
  ifs >> N;
  ifs.ignore();

  std::string tmp;
  for (int i = 0; i < N; ++i) {
    std::getline(ifs, tmp);

    str += tmp + '\n';
  }

  for (int i = 0; i < str.size(); ++i) {
    str[i] = encode(str[i]);
  }

  std::cout << "Your encoded input:\n" << str;
}
