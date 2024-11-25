#include <iostream>

class Shape {
  int x, y;

public:
  Shape(int x, int y) : x(x), y(y) {}

  int area() const;

  void print() {
    std::cout << "Shape\n";
  }
};
