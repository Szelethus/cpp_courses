#include <iostream>

class Shape {
  double x, y;

public:
  Shape(double x, double y) : x(x), y(y) {}

  void printCenter() const {
    std::cout << "(" << x << ", " << y << ")\n";
  }

  virtual void print() const {
    printCenter();
  }

  // pure virtual function
  virtual double area() const = 0;
};

class Circle : public Shape {
  double r;

public:
  Circle(double x, double y, double r)
      : Shape(x, y), r(r) {}

  double area() const override {
    return r * r * 3.14;
  }

  void print() const override {
    // explicit namespace resolution
    this->Shape::print();
    std::cout << "Radius: " << r << '\n';
  }
};

class Rectangle : public Shape {
  double w, h;

public:
  Rectangle(int x, int y, int w, int h)
      : Shape(x, y), w(w), h(h) {}

  double area() const override {
    return w * h;
  }

  void print() const override {
    // explicit namespace resolution
    this->Shape::print();
    std::cout << "Width: " << w
              << " Height: " << h << '\n';
  }
};

class Square : public Rectangle {
public:
  Square(int x, int y, int w) : Rectangle(x, y, w, w) {}
};

void printIfRectangle(Shape *sp) {
  Rectangle *ptr = dynamic_cast<Rectangle *>(sp);

  if (ptr)
    ptr->print();
}

int main() {
  //Shape sp(4,5);
  Circle c(1,2,10);
  Rectangle r(1,2,10,12);
  Square s(0,0,100);

  Rectangle *rptr = &s;
  Shape *sptr = rptr;

  printIfRectangle(&c);
  printIfRectangle(&r);
  printIfRectangle(&s);
}
