#include <iostream>

namespace alma {
int x;
} // end of namespace alma

namespace korte {
int x;
} // end of namespace korte

int main() {
  alma::x = 5;
  korte::x = 9;

  std::cout << "Hello World!\n";
}
