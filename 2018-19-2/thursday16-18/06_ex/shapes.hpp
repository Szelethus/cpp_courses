#ifndef AKARMI
#define AKARMI

#include <algorithm>
#include <vector>

class shape {
public:
  virtual int area() const = 0;
  virtual ~shape() {}
  virtual shape *clone() const = 0;
};

class rectangle : public shape {
  int x;
  int y;
public:
  rectangle(int a, int b): x(a), y(b) {}
  int area() const { return x * y; }
  rectangle *clone() const {
    return new rectangle(*this);
  }
};

class square : public shape {
  int a;
public:
  square(int b): a(b) {}
  int area() const { return a * a; }
  square *clone() const {
    return new square(*this);
  }
};

int area_adder(int sum, shape *s) {
  return sum + s->area();
}

struct area_adder_functor {
  int operator()(int sum, shape *s) {
    return sum + s->area();
  } 
};

class shape_group : public shape {
  std::vector<shape *> shapes;
public:
  shape_group() {}

  shape_group(const shape_group &sg) {
    for (shape *s : sg.shapes) {
      shapes.push_back(s->clone());
    }
  }

  shape_group &operator=(const shape_group &sg) {
    if (&sg == this)
      return *this;
    for (shape *s : shapes) {
      delete s;
    }
    shapes.clear();
    for (shape *s : sg.shapes) {
      add(*s);
    }
    return *this;
  }
/*  
  shape_group &operator=(shape_group sg) {
    shapes.swap(sg.shapes);
    return *this;
  }
*/

  ~shape_group() {
    for (shape *s : shapes) {
      delete s;
    }
  }

  void add(const shape &s) {
    shapes.push_back(s.clone());
  }

  int area() const {
/*
    int sum = 0;
    for (shape *s : shapes) {
      sum += s->area();
    }
    return sum;
*/
    std::accumulate(shapes.begin(), shapes.end(),
                    0, area_adder);
  }

  shape_group *clone() const {
    return new shape_group(*this);
  }
};

#endif












