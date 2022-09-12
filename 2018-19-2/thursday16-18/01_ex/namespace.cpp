#include <iostream>
#include <algorithm>

using namespace std;

namespace alma {

namespace balma {

void f() {
  cout << "balma\n";
} 

} // end of namespace balma

} // end of namespace alma


int main() {

  alma::balma::f();

  cout << "Hello!\n";  
}
