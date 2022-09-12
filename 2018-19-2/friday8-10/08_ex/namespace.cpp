#include <iostream>

using namespace std;

namespace alma {

void f() {
  std::cout << "alma\n";
}

} // end of namesapce alma

namespace balma {

void f() {
  std::cout << "balma\n";
}

} // end of namesapce balma

using namespace balma;

void f() {
  std::cout << "f\n";
}

int main() {
  cout << "hello\n";
  alma::f();
  balma::f();
  ::f();
}
