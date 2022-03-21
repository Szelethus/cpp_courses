#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

void printPolynom(std::vector<int> polynom) {
  for (int i = 0; i < polynom.size(); ++i) {
    std::cout << polynom.at(i) << "*x^" << i;
    if (i != polynom.size() - 1) {
      std::cout << " + ";
    }
  }
  std::cout << '\n';
}

std::vector<int> readPolynom(std::istream &in) {
  std::vector<int> polynom;

  int input;
  while (in >> input) {
    polynom.push_back(input);
  }

  return polynom;
}

int valueAt(std::vector<int> polynom, int x) {
  int result = 0;
  for (int i = 0; i < polynom.size(); ++i) {
    result = result + polynom[i] * std::pow(x, i);
  }

  return result;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Please provide a filename: "
              << argv[0] << " <filename>\n";
    return 1;
  }

  std::ifstream ifs(argv[1]);

  if (ifs.fail()) {
    std::cout << "Failed to open file '" << argv[1] << "'\n";
    return 1;
  }

  std::vector<int> polynom = readPolynom(ifs);

  printPolynom(polynom);

  int x = 5;

  std::cout << "polynom at x=" << x << " is: "
            << valueAt(polynom, x);

}
