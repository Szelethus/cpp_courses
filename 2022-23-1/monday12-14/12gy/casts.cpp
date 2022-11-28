#include <iostream>

struct Shape {
  int x = 0, y = 0;
  virtual void print() = 0;
};

struct Deltoid : public Shape {
  virtual void print() { std::cout << "Deltoid\n"; }
};

struct Rombus : public Shape {
  virtual void print() { std::cout << "Rombus\n"; }
};

struct Square : public Deltoid, public Rombus {
  void print() { std::cout << Deltoid::x << ' ' << Deltoid::y << '\n'; }
};

int main() {
  Shape *sp = new Rombus;

  if (Square *dp = dynamic_cast<Square *>(sp)) {
    dp->print();
  }

  if (Deltoid *dp = dynamic_cast<Deltoid *>(sp)) {
    dp->print();
  }

  if (Rombus *dp = static_cast<Rombus *>(sp)) {
    dp->print();
  }

  const int i = 0;
  int *ptr = const_cast<int *>(&i);

  long l = reinterpret_cast<long>(sp);
}
