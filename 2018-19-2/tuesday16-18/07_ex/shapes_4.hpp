#ifndef SHAPES_HPP
#define SHAPES_HPP

#include <vector>
#include <algorithm>

struct shape {
  virtual int area() const = 0;

  virtual shape *clone() const = 0;

  virtual ~shape() {}
};

struct rectangle : public shape {
  int width;
  int height;

  rectangle(int width, int height) : width(width), height(height) {}

  int area() const override {
    return width * height;
  }
  
  virtual shape *clone() const override {
    return new rectangle(*this);
  }
};

struct square : public shape {
  int width;

  square(int width) : width(width) {}

  int area() const override {
    return width * width;
  }
  
  virtual shape *clone() const override {
    return new square(*this);
  }
};

struct AddArea {
  int operator()(int sum, const shape *s) {
    return sum + s->area();
  }
};

struct shape_group {
  std::vector<shape *> shapes;

  void add(const shape &s) {
    shapes.push_back(s.clone());
  }

  ~shape_group() {
    for (shape *s : shapes)
      delete s;
  }

  int area() const {
    return std::accumulate(shapes.begin(), shapes.end(), 0, AddArea());
  }
};

#endif
