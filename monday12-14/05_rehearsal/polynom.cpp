#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>

std::vector<int> readPolynom(std::istream &in) {
  std::vector<int> polynom;

  int input;
  while (in >> input) {
    polynom.push_back(input);
  }

  return polynom;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Please provide a file name, for example: "
              << argv[0] << " <filename>\n";
    return 1;
  }

  std::ifstream ifs(argv[1]);

  if (ifs.fail()) {
    std::cout << "Failed to open '" << argv[1] << "', because: ";
    std::cout << strerror(errno) << '\n';
  }

  std::vector<int> polynom = readPolynom(std::cin /*anyád*/);

  int result = 0;
  int x = 5;
  for (int i = 0; i < polynom.size(); ++i) {
    result = result + polynom[i] * std::pow(x, i);
  }

  for (int i = 0; i < polynom.size(); ++i) {
    std::cout << polynom[i] << "x^" << i;
    if (i != polynom.size() - 1)
      std::cout << " + ";
  }
  std::cout << '\n';

  std::cout << "if x = " << x << ", then this polynom is " << result << '\n';
}
