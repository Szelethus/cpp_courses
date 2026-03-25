#include <iostream>
#include <string>
#include <vector>

std::string to_string(std::vector<int> v);
std::string coeff_to_string(std::vector<int> v, int idx);

int main() {
  // test cases: each line is a polynom
  std::vector<std::vector<int>> polynoms{
      {-2, 0, 5, -3, 8},
      {42, 0, 5, 0, 8, 9},
      {-42, 0, 5, 0, 8, -9},
      {0, 0, 5, 0, 8, -9},
      {0, 0, -5, 0, 8, -9},
      {0, 0, -5, 0, 8, -9, 0, 0}, // test trailing zeros
      {8},                        // test constant polynom
      {-8},
      {0, 0, 0}, // test null polynom
      {0},       // test null polynom
      {}         // consider empty vector as null polynom
  };

  for (auto vec : polynoms) // execute to:string() for all
  {
    std::string s = to_string(vec);
    std::cout << s << '\n';
  }
  return 0;
}

std::string to_string(std::vector<int> v) {
  // special cases: empty vector and null polynom
  if (v.empty() || (1 == std::ssize(v) && 0 == v[0])) {
    return "";
  }
  std::string res = "";
  // use std::ssize(v) for C++20, use v.size() for earlier
  for (int i = std::ssize(v); i > 0; --i) {
    res += coeff_to_string(v, i - 1);
  }
  return res;
}
// helper function to process one coefficient
std::string coeff_to_string(std::vector<int> v, int i) {
  std::string r = "";
  int coeff = v[i];

  if (0 == coeff) // if zero, skip
    return r;
  // print the sign if necessary
  if (coeff < 0)
    ; // nothing to do: std::to_string(coeff) prints - sign
  else if (i < std::ssize(v) - 1)
    r += "+"; // write + sign only when not highest degree
  r += std::to_string(coeff);

  if (i > 0) // write X^i only for degree > 0
  {
    r += "X^";
    r += std::to_string(i);
  }
  return r;
}
