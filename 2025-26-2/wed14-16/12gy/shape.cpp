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
};

class Square : public Rectangle {
public:
  Square(int x, int y, int w) : Rectangle(x, y, w, w) {}
};

int main() {
  Circle c(1,2,10);

  // Shape egy absztrakt típus, lévén van tisztán virtuális
  // függvénye
  // absztrakt típus nem példányosítható
  //Shape s(3,4);
  Rectangle r(4,5,8,9);

  Shape *sptr = &c;

  std::cout << sptr->area() << '\n';
  sptr->print();
}
