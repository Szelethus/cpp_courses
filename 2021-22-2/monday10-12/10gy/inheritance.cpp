#include <iostream>
#include <cmath>

class Shape {
public:
  virtual double area() const = 0;

  virtual double perimeter() const = 0;

  virtual void print() const = 0;

  ~Shape() {}
};

class Rectangle : public Shape {
protected:
  double width;
  double height;

public:
  Rectangle(double _width, double _height)
    : width(_width), height(_height) {}

  double area() const override {
    return width * height;
  }

  double perimeter() const override {
    return (width + height) * 2;
  }

  virtual void print() const override {
    std::cout << "Rectangle [width=" << width << ", height="
              << height << "]\n";
  }
};

class Square : public Rectangle {
public:
  Square(double x) : Rectangle(x, x) {}

  virtual void print() const override {
    std::cout << "Square [width=" << width << "]\n";
  }
};

class Circle : public Shape {
  double radius;

public:
  Circle(double _radius) : radius(_radius) {}

  double area() const override {
    return std::pow(radius, 2) * M_PI;
  }

  double perimeter() const override { return 2 * radius * M_PI; }

  virtual void print() const override {
    std::cout << "Circle [radius=" << radius << "]\n";
  }
};

int main() {
  Circle c{4};
  Rectangle r{4, 5.6};
  Square sq{6};

  Shape &sr = sq;

  sr.print();
}
