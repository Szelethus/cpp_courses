#include <iostream>

class Shape {
protected:
  int x, y;

public:
  Shape(int x, int y) : x(x), y(y) {}

  virtual int area() {
    return -1;
  }

  void print(){}
};

class Circle : public Shape {
  int r;

public:
  Circle(int x, int y, int r) : Shape(x, y), r(r) {}

  int area() override {
    return r * r * 3.14;
  }
  void print(){}
};

int main() {
  Circle c{1,2,3};
  Shape *s = &c;
  std::cout << s->area() << '\n';
}
