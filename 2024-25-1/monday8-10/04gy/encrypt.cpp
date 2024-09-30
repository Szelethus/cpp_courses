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

int main(int argc, char **argv) {
  if (argc != 2) {
    return -1;
  }

  std::ifstream ifs(argv[1]);
  if(!ifs)
    return -1;
  int i;
  ifs >> i;

  std::string input;

  std::string tmp;
  for (int j= 0; j < i; ++j) {
    std::getline(ifs, tmp);
    input += tmp + '\n';
  }

  for (int i = 0; i < input.size(); ++i) {
    input[i] = encode(input[i]);
  }

  std::cout << "Your encoded input:\n" << input << '\n';
}
