#include <iostream>

namespace outer {
int x;
} // end of namespace outer

namespace outer {
int y;
  namespace inner {
  int y;
  } // end of namespace outer::inner
} // end of namespace outer

int main() {
  std::cout << outer::x << '\n';
  // ADL: Argument Dependent Lookup
  operator<<(std::cout, "Hello");
  std::string s;

}
