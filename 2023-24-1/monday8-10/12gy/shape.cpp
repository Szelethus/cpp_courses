#include <iostream>

class Shape {
protected:
  int x, y;

public:
  Shape(int x, int y) : x(x), y(y) {}

  virtual int area() const { return -1; }
};

class Circle : public Shape {
  int r;

public:
  Circle(int x, int y, int r) : Shape(x, y), r(r) {}

  int area() const {
    return r * r * 3.14;
  }
};

int main() {
  Circle c(0,0,4);
  Shape &s = c;
  std::cout << s.area() << '\n';
}
