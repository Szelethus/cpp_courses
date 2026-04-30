#include <iostream>

class Shape {
protected:
  int x, y;

public:
  Shape(int x, int y) : x(x), y(y) {}

  void print() {
    std::cout << "(" << x << ", " << y << ")\n";
  }

  int area() {
    return -1;
  }
};

class Circle : public Shape {
  int r;

public:
  Circle(int x, int y, int r) : Shape(x, y), r(r) {}

  void print() {
    std::cout << "(" << x << ", " << y << ", " << r << ")\n";
  }

  int area() {
    return 3.14 * r * r;
  }
};

int main() {
  Circle c(1, 2, 6);
}
