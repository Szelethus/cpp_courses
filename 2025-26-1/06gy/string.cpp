#include <iostream>

int main() {
  std::string t = "hello";

  for (std::string::iterator it = t.begin(); it != t.end(); ++it) {
    std::cout << *it << '\n';
  }
}
