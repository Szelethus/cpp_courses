#include <iostream>
#include <fstream>

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

int main() {
  std::ifstream ifs("input.txt");
  if (ifs.fail()) {
    std::cout << "Failed to open input file!\n";
    return 1;
  }

  std::string input;

  while (true) {
    std::string tmp;
    ifs >> tmp;

    if (ifs.fail())
      break;

    input += tmp + ' ';
  }

  for (int i = 0; i < input.size(); ++i)
    input[i] = encode(input[i]);

  std::cout << "Your encoded character: " << input << '\n';
}
