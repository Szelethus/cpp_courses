#include <iostream>

class Shape {
protected:
  int x, y;

public:
  Shape(int x, int y) : x(x), y(y) {};
};

class Rectangle : virtual public Shape {
public:
  Rectangle(int x, int y) : Shape(x, y) {}
};


class Deltoid : virtual public Shape {
public:
  Deltoid(int x, int y) : Shape(x, y) {}
};

class Square : public Rectangle,
               public Deltoid {
  int c;
public:
  Square(int x, int y, int c)
      : Shape(x, y),
        Rectangle(x, y),
        Deltoid(x, y) {}
};

int main() {
  Square sq(1,2,9);
}
