#include <iostream>

class Shape {
protected:
  int x, y;

public:
  Shape(int x, int y) : x(x), y(y) {}

  virtual int area() const = 0;

  virtual void print() {
    std::cout << "Shape\n";
  }
};

class Circle : public Shape {
  int r;

public:
  Circle(int x, int y, int r) : Shape(x, y), r(r) {}

  int area() const {
    return r * r * 3.14;
  }

  void print() override {
    std::cout << "Circle\n";
  }
};

void foo(Shape *s) {
  Circle *c = dynamic_cast<Circle*>(s);

  if (c)
    std::cout << "its a circle\n";
}

Shape* bar(Circle *c) {
  
}

int main() {
  Circle c(0,0,1);
  
  Shape *s = &c;

  s->print();

  foo(s);
}
