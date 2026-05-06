#include <iostream>

struct Int {
  int i;
};

struct Float {
  float f;

  Float() {}
  explicit Float(Int i) : f(i.i) {};
};

int main() {
  Int i{5};
  
  Float f;

  f = static_cast<Float>(i);
}
