#include <iostream>
#include <vector>

int pow(int n, int exponent) {
  int result = n;
  for (int i = 0; i < exponent - 1; ++i) {
    result = result * n;
  }

  return result;
}

int main() {
  std::vector<int> polynom;
  std::cout << "Please provide a list of coefficients: ";

  int coeff;
  std::cin >> coeff;

  while (!std::cin.fail()) {
    polynom.push_back(coeff);
    std::cin >> coeff;
  }

  std::cout << "Your polynom coefficients: ";
  for (int i = 0; i < polynom.size(); ++i) {
    std::cout << polynom[i] << ' ';
  }
  std::cout << '\n';

  int result = 0;
  const int X = 5;
  for (int i = 0; i < polynom.size(); ++i) {
    result += polynom[i] * pow(X, i);
  }

  std::cout << "result: " << result << '\n';

}
