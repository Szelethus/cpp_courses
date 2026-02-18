#include <iostream>

namespace korte {
  int x;
} // end of namespace korte

namespace alma {
  int x;
} // end of namespace alma

using namespace std;

int main() {

  korte::x = 5;

  alma::x = 8;

  cout << "Hello World!\n";
}
