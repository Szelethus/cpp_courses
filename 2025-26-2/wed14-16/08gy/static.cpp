#include <iostream>

int global;

// statikus változó
static int st;

void g() {
  // függvényre statikus változó
  static int i = 0;
  std::cout << ++i << '\n';
}

struct A {
  // osztályra statikus változók
  static int count;
  A() {
    count++;
    std::cout << "A instantiated " << count
              << " times\n";
  }

  // statikus tagfüggvény
  static void foo() {
    std::cout << "foo!\n";
  }
};

// osztályon kívül kell definiálni
int A::count = 0;

// statikus függvény
static int max(int a, int b) {
  if (a > b)
    return a;
  return b;
}

int main() {
  A a1, a2, a3;

  std::cout << A::count << '\n';

}
