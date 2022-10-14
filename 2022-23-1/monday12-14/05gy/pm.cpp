#include <iostream>

// (1) Mit ir ki az alábbi program?
void f(const int (&t)[5]) {
  std::cout << "1.: " << sizeof(t) << '\n';
  std::cout << "2.: " << sizeof(t[0]) << '\n';
  std::cout << "3.: " << t[0] << '\n';
  std::cout << "4.: " << sizeof(&t) << '\n';
  std::cout << "5.: " << sizeof(*t) << '\n';
  std::cout << "6.: " << *t << '\n';
//  std::cout << "7.: " << sizeof((*t)[0]) << '\n';
}

int main() {
  int t[5];
  f(t);
}

// (2) Milyen objektumokat kell *mindig* inicializálnunk?

// (3) Irj egy header guardot!

// (4) Mi a feladata a konstruktornak?
