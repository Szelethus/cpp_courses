#include <iostream>

class Printable {
public:
  virtual void print() const = 0;
};

class HasArea {
public:
  virtual int area() const = 0;
};

class Circle : public Printable, public HasArea {
  int x, y;
  int r;

public:
  Circle(int x, int y, int r) : x(x), y(y), r(r) {}

  virtual void print() const override {
    std::cout << x << ", " << y << '\n';
  }

  virtual int area() const override {
    return r * r * 3.14;
  }
};

void print(const Printable &p) {
  p.print();
}

int main() {
  Circle sh{1, -3, 10};

  print(sh);
}
