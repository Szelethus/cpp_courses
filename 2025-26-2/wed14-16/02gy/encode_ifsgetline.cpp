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
  std::ifstream ifs("input.txt");
  if (ifs.fail()) {
    std::cout << "Failed to open file!\n";
    return -1;
  }

  int N;
  ifs >> N;
  ifs.ignore();

  std::string str;
  std::string tmp;

  std::getline(ifs, tmp);
  for (int i = 0; i < N; ++i) {
    str += tmp + '\n';
    std::getline(ifs, tmp);
  }

  for (int i = 0; i < str.size(); ++i) {
    str[i] = encode(str[i]);
  }

  std::cout << "Your encoded input is:\n" << str;
}
