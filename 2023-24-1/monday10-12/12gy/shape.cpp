#include <iostream>

class Shape {
protected:
  int x, y;

public:
  Shape(int x, int y) : x(x), y(y) {}

  virtual int area() const = 0;
};

class Circle : public Shape {
  int r;

public:
  Circle(int x, int y, int r) : Shape(x, y), r(r) {}

  virtual int area() const override {
    return r * r * 3.14;
  }
};

class Rectangle : public Shape {
  int width, height;

public:
  virtual int area() const override {
    return width * height;
  }
};

int main() {
  Circle c(0,0,3);
  Shape *s = &c;

  std::cout << s->area() << '\n';

  Circle *cp = dynamic_cast<Circle*>(s);
}
