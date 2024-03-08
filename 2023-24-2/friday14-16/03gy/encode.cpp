#include <ios>
#include <iostream>
#include <fstream>

char encode(char c) {
  std::string from = "aeiou";
  std::string to   = "eioua";

  for (int i = 0; i < from.size(); ++i) {
    if (c == from[i])
      return to[i];
  }

  return c;
}

int main() {
  std::ifstream ifs("input.txt");
  
  if (ifs.fail()) {
    std::cout << "Failed to open 'input.txt'!\n";
    return 1;
  }

  int N;
  ifs >> N;
  ifs.ignore();

  std::string input;

  for (int i = 0; i < N; ++i) {
    std::string tmp;
    std::getline(ifs, tmp);

    input += tmp + '\n';
  }

  for (int i = 0; i < input.size(); ++i)
    input[i] = encode(input[i]);

  std::cout << input << '\n';
}
