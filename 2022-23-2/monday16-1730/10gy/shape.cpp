#include <iostream>

struct Shape {
  virtual int area() = 0;
  virtual void name() {}
};

struct Circle : public Shape {
  int r;

  Circle(int r) : r(r) {}

  int area() {
    return r*r*3.14;
  }

  virtual void name() {
    std::cout << "Circle\n";
  }
};

int main() {
  Shape *sh = nullptr;
  Circle c{3};

  sh = &c;

  (*sh).name();
}

//class Rectangle : public Shape {
//protected:
//  int width;
//  int height;
//public:
//  Rectangle(int w, int h) : width(w), height(h) {}
//
//  int area() {
//    return width*height;
//  }
//
//  void name() {
//    std::cout << "Rectangle\n";
//  }
//};
//
//struct Square : public Rectangle {
//  Square(int x) : Rectangle(x, x) {}
//
//  void name() {
//    std::cout << "Square\n" << width << ' ' << height;
//  }
//};
