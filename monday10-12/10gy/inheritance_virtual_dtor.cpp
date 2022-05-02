#include <iostream>
#include <cmath>

class Shape {
public:
  double area() const {
    return -1;
  }

  double perimeter() const {
    return -1;
  }

  virtual void print() const {
    std::cout << "Too general!\n";
  }

  virtual ~Shape() {}
};

class Rectangle : public Shape {
  double width;
  double height;

  int *ptr;

public:
  Rectangle(double _width, double _height)
    : width(_width), height(_height) {
    ptr = new int;
  }

  ~Rectangle() {
    delete ptr;
  }

  double area() const {
    return width * height;
  }

  double perimeter() const {
    return (width + height) * 2;
  }

  virtual void print() const override {
    std::cout << "Rectangle [width=" << width << ", height="
              << height << "]\n";
  }
};

class Circle : public Shape {
  double radius;

public:
  Circle(double _radius) : radius(_radius) {}

  double area() const {
    return std::pow(radius, 2) * M_PI;
  }

  double perimeter() const { return 2 * radius * M_PI; }

  virtual void print() const override {
    std::cout << "Circle [radius=" << radius << "]\n";
  }
};

int main() {
  Shape *ptr = new Rectangle{2.2, 7.8};

  delete ptr;
}
