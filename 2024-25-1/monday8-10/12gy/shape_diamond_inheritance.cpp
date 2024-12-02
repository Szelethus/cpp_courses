#include <iostream>

struct Shape {
  int x, y;
};

struct Rombus : virtual public Shape {

};

struct Trapezoid : virtual public Shape {

};

struct Square : public Trapezoid, public Rombus {
  
  void print() {
    std::cout << "(x, y): " << x << ", "
                            << y << '\n';
  }
};

int main() {
  Square sq;
  sq.x = 0;
  sq.y = 2;
  sq.print();
}
