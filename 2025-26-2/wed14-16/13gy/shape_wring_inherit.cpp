#include <iostream>

class Shape {
protected:
  int x, y;

public:
  Shape(int x, int y) : x(x), y(y) {};
};

class Rectangle : public Shape {
protected:
  int a, b;
public:
  Rectangle(int x, int y, int a, int b)
      : Shape(x, y), a(a), b(b) {}
};


class Deltoid : public Shape {
protected:
  int a, b;
public:
  Deltoid(int x, int y, int a, int b)
      : Shape(x, y), a(a), b(b) {}
};

class Square : public Rectangle, public Deltoid {
public:
  Square(int x, int y, int c)
      : Rectangle(x, y, c, c) {}
};

int main() {
  Square sq(1,2,9);
}
