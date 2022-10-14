#include <iostream>

// (1) Mit ir ki az alábbi program? Helyes-e?

#define VALUE_MUL 5 * 3
#define VALUE_PLUS 5 + 3

void f() {
  std::cout << "1.: " << VALUE_MUL + 2 << '\n';
  std::cout << "2.: " << VALUE_MUL * 2 << '\n';
  std::cout << "3.: " << VALUE_PLUS + 2 << '\n';
  std::cout << "4.: " << VALUE_PLUS * 2 << '\n';
}

// (2) Mit ir ki az alábbi program? Helyes-e?

int x;
void g1() {
  int x;
  {
    static int x;
    std::cout << "1.: " << x << '\n';
    std::cout << "2.: " << ::x << '\n';
  }
}

int y = 2;
void g2() {
  int y = 3;
  {
    int *y = new int{4};
    std::cout << "3.: " << y << '\n';
    std::cout << "4.: " << ::y << '\n';
    delete y;
  }
}

// (3) Irj egy header guardot!

// (4) Mit ir ki az alábbi program? Helyes-e?

int *h1() {
  int i = 0;
  return &i;
}

int *h2() {
  return new int {2};
}


int main() {
  f();
  g1();
  g2();

  int *i1 = h1();
  std::cout << *i1 << '\n';
  int *i2 = h2();
  std::cout << *i2 << '\n';
}


