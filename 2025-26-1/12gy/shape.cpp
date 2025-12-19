#include <iostream>

class Shape {
protected:
  int x, y;

public:
  Shape(int x, int y) : x(x), y(y) {}

  // tisztán virtuális fv (pure virtual)
  virtual int area() = 0;

  virtual void print() {
    std::cout << "Coordinates: " << x << ", " << y << '\n';
  }
};

class Circle : public Shape {
  int r;

public:
  Circle(int x, int y, int r) : Shape(x, y), r(r) {}

  int area() override {
    return r * r * 3.14;
  }

  void print() override {
    Shape::print();
    std::cout << "Radius: " << r << '\n';
  }
};

int main() {
  // Shape absztrakt
  // Shape sh{1,2};

  Circle c{1,2,3};
  Shape *s = &c;
  std::cout << s->area() << '\n';
  s->print();
}
