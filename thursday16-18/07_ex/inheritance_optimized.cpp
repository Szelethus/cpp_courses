#include <iostream>
#include <list>

struct Shape {
  int x, y;

  Shape() = default;

  Shape(int x, int y) : x(x), y(y) {}

  virtual int area() const = 0;

  virtual ~Shape() = default;

  void printCenter() const {
    std::cout << "x: " << x << " y: " << y << '\n';
  }

  virtual Shape *clone() const = 0;
};

struct Circle : public Shape {
  int r;

  Circle(int x, int y, int r) : Shape(x, y), r(r) {}
  
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

  Rectangle(int x, int y, int width, int height)
    : Shape(x, y), width(width), height(height), ptr(new int) {}

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

std::list<Shape *>::iterator doubleRadiusOfCircles(std::list<Shape *>::iterator begin) {
  int count = 0;

  while(count++ != 4) {
    Circle *ptr = static_cast<Circle *>(*begin);
    ptr->r *= 2;
  }

  return begin;
}

std::list<Shape *>::iterator setHeightTo3ForRectangles(std::list<Shape *>::iterator begin) {
  int count = 0;

  while(count++ != 4) {
    Rectangle *ptr = static_cast<Rectangle *>(*begin);
    ptr->height = 3;
  }

  return begin;
}

int main() { 
  std::list<Shape *> vec;

  vec.push_back(new Rectangle(2, 3, 4, 10));
  vec.push_back(new Rectangle(2, 3, 3, 1));
  vec.push_back(new Rectangle(2, 3, 1, 40));
  vec.push_back(new Rectangle(2, 3, 0, 1));

  vec.push_back(new Circle(5, 9, 1));
  vec.push_back(new Circle(5, 9, 3));
  vec.push_back(new Circle(5, 9, 6));
  vec.push_back(new Circle(5, 9, 2));

  for (Shape *s : vec)
    std::cout << s->area() << '\n';


  auto it = setHeightTo3ForRectangles(vec.begin());
  doubleRadiusOfCircles(it);

  std::cout << '\n';

  for (Shape *s : vec)
    std::cout << s->area() << '\n';

  for (Shape *s : vec)
    delete s;
}
