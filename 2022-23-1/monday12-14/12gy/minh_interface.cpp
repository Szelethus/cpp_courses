#include <iostream>

struct Printable {
  virtual void print() const = 0;

  int getId() { return 0; }
};

class Shape : public Printable{
protected:
  int x, y;

public:
  Shape(int x, int y) : x(x), y(y) {}

  virtual void print() const {
    std::cout << "(x: " << x << ", y: " << y << ")";
  }
};

int main() {
  Shape s(0,0);
}
