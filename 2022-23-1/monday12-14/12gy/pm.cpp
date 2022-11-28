#include <iostream>
#include <set>

// (1) Hozzunk létre egy halmazt az STL segítségével, mely
// string-eket az első betűjük szerint növekvő sorrendbe rendez!
// tfh. nincsenek üres stringek

struct FirstLetterLess {
  bool operator()(const std::string &lhs, const std::string &rhs) {
    return lhs[0] < rhs[0];
  }
};

std::set<std::string, FirstLetterLess> firstLetterStringSet;

// (2) Miért veszélyes az std::map [] operátora?

// (3) Mi a különbség egy input iterátor és egy forward iterátor
// között?

// (4) Mi az az iterátor invalidáció (std::vector esetében)?

// (5) Nevezz meg az std::vector egy tagfüggvényét, mely iterátor
// invalidációhoz vezethet!

// (6) Mit ír ki az alábbi program:

struct A {
  A() {
    std::cout << "A\n";
  }
  ~A() {
    std::cout << "~A\n";
  }
};

struct B : public A {
  B() {
    std::cout << "B\n";
  }
  ~B() {
    std::cout << "~B\n";
  }
};

int main() {
  std::cout << "1.:\n";
  {
    B b;
  }

  std::cout << "2.:\n";
  {
    A *a = new B;
    delete a;
  }
}
