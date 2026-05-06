#include <iostream>

class Shape {
  int x, y;

public:
  Shape(int x, int y) : x(x), y(y) {}

  void printCenter() {
    std::cout << "(" << x << ", " << y << ")\n";
  }

  virtual void print() {
    printCenter();
  }

  // pure virtual fn
  virtual int area() = 0;
};

class Circle : public Shape {
  int r;

public:
  Circle(int x, int y, int r) : Shape(x, y), r(r) {}

  virtual int area() override {
    return r * r * 3.14;
  }
  
  virtual void print() override {
    // explicit namespace resolution
    Shape::print();
    std::cout << "Radius: " << r << '\n';
  }
};

class Rectangle : public Shape {
  int w, h;

public:
  Rectangle(int x, int y, int w, int h)
      : Shape(x, y), w(w), h(h) {}

  int area() override {
    return w*h;
  }

  virtual void print() override {
    // explicit namespace resolution
    Shape::print();
    std::cout << "Width: " << w << " Height: " << h << '\n';
  }
};

class Square : public Rectangle {
public:
  Square(int x, int y, int w) : Rectangle(x, y, w, w) {}
};

void printIfRectangle(Shape *ptr) {
  Rectangle *cptr = dynamic_cast<Rectangle *>(ptr);

  if (cptr) {
    cptr->print();
  }
}

int main() {
  Circle c(1,2,10);
  Rectangle r(4,5,8,9);
  Square sq(3,4,99);

  Shape *scptr = &c;
  Shape *srptr = &r;

  printIfRectangle(scptr);
  printIfRectangle(srptr);
  printIfRectangle(&sq);
}
