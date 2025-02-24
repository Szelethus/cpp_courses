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

  std::string input;

  std::string tmp;
  while(true) {
    std::getline(ifs, tmp);
    if (ifs.fail())
      break;
    input += tmp + '\n';
  }

  for (int i = 0; i < input.size(); ++i) {
    input[i] = encode(input[i]);
  }

  std::cout << "Your encoded character: " << input << '\n';
}
