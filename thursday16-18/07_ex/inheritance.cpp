#include <iostream>
#include <vector>

struct Shape {
  int x, y;

  Shape() = default;

  virtual int area() const = 0;

  virtual ~Shape() = default;

  void printCenter() const {
    std::cout << "x: " << x << " y: " << y << '\n';
  }

  virtual Shape *clone() const = 0;
};

struct Circle : public Shape {
  int r;

  Circle(int r) : r(r) {}
  
  virtual int area() const override {
    return r * r * 3.14;
  }

  virtual Shape *clone() const override {
    return new Circle(*this);
  }
};

struct Rectangle : public Shape {
  int width, height;

  int *ptr;

  Rectangle(int width, int height)
    : width(width), height(height), ptr(new int) {}

  ~Rectangle() {
    delete ptr;
  }

  virtual int area() const override {
    return width * height;
  }

  virtual Shape *clone() const override {
    return new Rectangle(*this);
  }
};

void doubleRadiusOfCircles(std::vector<Shape *> &shapes) {
  for (Shape *s : shapes) {
    Circle *ptr = dynamic_cast<Circle *>(s);
    if (ptr == nullptr)
      continue;

    ptr->r *= 2;
  }
}

int main() { 
  std::vector<Shape *> vec;

  vec.push_back(new Rectangle(4, 10));
  vec.push_back(new Rectangle(3, 1));
  vec.push_back(new Rectangle(1, 40));
  vec.push_back(new Rectangle(0, 1));

  vec.push_back(new Circle(1));
  vec.push_back(new Circle(3));
  vec.push_back(new Circle(6));
  vec.push_back(new Circle(2));

  for (Shape *s : vec)
    std::cout << s->area() << '\n';

  doubleRadiusOfCircles(vec);

  std::cout << '\n';

  for (Shape *s : vec)
    std::cout << s->area() << '\n';

  for (Shape *s : vec)
    delete s;
}
