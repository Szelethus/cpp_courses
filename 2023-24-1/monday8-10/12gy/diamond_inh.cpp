#include <iostream>

struct Shape {
  int x = 0, y = 0;
};

struct Deltoid : virtual public Shape {
  virtual void print() {
    std::cout << "Deltoid\n";
  }
};

struct Rombus : virtual public Shape {
  virtual void print() {
    std::cout << "Rombus\n";
  }
};

struct Square : public Deltoid, public Rombus {
  void print() {
    std::cout << x << ' ' << y << '\n';
  }
};

int main() {
  Deltoid *sp = new Square;
  sp->print();
}
