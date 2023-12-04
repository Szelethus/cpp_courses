#include <iostream>

class Shape {
protected:
  int x, y;

public:
  void print() const {
    std::cout << "(x, y): " << x << ", " << y;
  }
};

class Circle : public Shape {
  int r;

public:
  void print() const {
    std::cout << "(x, y): " << x << ", " << y << ", r:" << r;
  }
};
