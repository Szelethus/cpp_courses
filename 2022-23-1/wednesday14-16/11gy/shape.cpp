#include <iostream>

class Shape {
protected:
  int x;
  int y;

public:
  Shape(int x, int y) : x(x), y(y) {}

  virtual void print() const {
    std::cout << x << ' ' << y << '\n';
  }

  virtual double area() const = 0;
};

class Circle : public Shape {
  int r = 0;

public:
  Circle(int x, int y, int r) : Shape(x, y), r(r) {}

  virtual void print() const override {
    std::cout << x << ' ' << y << ' ' << r << '\n';
  }

  virtual double area() const override {
    return r * r * 3.14;
  }
};

class Rectangle : public Shape {
  int width;
  int height;

public:
  virtual void print() const override {
    std::cout << x << ' ' << y << ' '
              << height << ' ' << width << '\n';
  }

  virtual double area() const override {
    return height * width;
  }
};

int main() {
  Circle c(0,0, 4);
  //Circle c2 = *static_cast<Circle *>(s);
}
