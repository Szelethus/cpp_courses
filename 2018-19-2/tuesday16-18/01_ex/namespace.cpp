#include <iostream>

namespace alma {

void f() {
  std::cout << "f\n";
}

} // end of namespace alma

namespace {

/*static*/ void g() {}

} // end of anonymous namespace

int main() {
  alma::f();
  std::cout << "HELLLO\n";  
}
