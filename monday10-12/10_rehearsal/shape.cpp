#include <iostream>
#include <vector>
#include <cmath>

class Shape {
public:
  virtual double area() const {
    return -1;
  }
  virtual double circumference() const {
    return -1;
  }
  virtual void print() const {
    std::cout << "Too general!\n";
  }
};

class Rectangle : public Shape {
  double width;
  double height;

public:
  Rectangle(double _width, double _height) : width(_width), height(_height) {}

  double area() const {
    return width * height;
  }
  double circumference() const {
    return (width + height) * 2;
  }
  void print() const {
    std::cout << "Rectangle [width: " << width << ", height: " << height << "]\n";
  }
};

class Circle : public Shape {
  double radius;

public:
  Circle(double _radius) : radius(_radius) {}

  double area() const {
    return std::pow(radius, 2) * M_PI;
  }
  double circumference() const {
    return 2 * radius * M_PI;
  }
  void print() const {
    std::cout << "Circle [radius: " << radius << "]\n";
  }
};

int main() {
  Circle c{5.6};
  Shape *sh = &c;
  sh->print();
}

