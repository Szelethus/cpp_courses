#include <cstdint>
#include <iostream>

class Shape {
protected:
  Shape(int x, int y) : x(x), y(y) {}

  int x;
  int y;

public:
  virtual void print() const {
    std::cout << x << ' ' << y << ' ';
  }
  
  virtual double terulet() = 0;
};

class Circle : public Shape {
  int r = 0; 

public:
  // Konstruktor delegációval meghvjuk az ősosztály konstruktorát
  Circle(int x, int y, int r) : Shape(x, y), r(r) {}

  virtual void print() const override {
    Shape::print();
    std::cout << r << '\n';
  }

  virtual double terulet() override {
    return r * r * 3.14;
  }
};

class Rectangle : public Shape {
  int width = 0; 
  int height = 0; 

public:
  Rectangle(int x, int y, int width, int height)
    : Shape(x, y), width(width), height(height) {}
  virtual void print() const override {
    Shape::print();
    std::cout << width << ' ' << height << '\n';
  }

  virtual double terulet() override {
    return width * height;
  }
};

int main() {
  Circle c(0,0,4);
  Shape *p = &c;
  p->print();
}
