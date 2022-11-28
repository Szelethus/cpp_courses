#include <iostream>

struct Printable {
  virtual void print() const = 0;
  
  virtual int getId() { return -1; }
};

struct Drawable {
  virtual void draw() const { }
  
  virtual int getId() { return -1; }
};

void print(Printable *p) {
  p->print();
}

class Shape : public Printable, public Drawable {
protected:
  int x, y;

public:
  Shape(int x, int y) : x(x), y(y) {}

  virtual void print() const {
    std::cout << "(x: " << x << ", y: " << y << ")";
  }
  virtual int getId() { return -1; }
};

int main() {
  Shape s(0,0);
  s.getId();

}
