#include <iostream>

struct Shape {
  virtual void foo() {}
};

struct Rectangle : public Shape {};
struct Square : public Rectangle {};

struct Circle : public Shape {};

int main() {
  Circle c;

  // upcast
  Shape *s = &c;

  Circle *cp = dynamic_cast<Circle *>(s);
  if (!cp) {
    std::cout << "Failed to downcast!\n";
    return -1;
  }
}
