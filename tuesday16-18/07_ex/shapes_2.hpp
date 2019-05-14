#ifndef SHAPES_HPP
#define SHAPES_HPP

struct rectangle {
  int width;
  int height;

  rectangle(int width, int height) : width(width), height(height) {}

  int area() const {
    return width * height;
  }
};

struct square {
  int width;

  square(int width) : width(width) {}

  int area() const {
    return width * width;
  }
};

#endif
