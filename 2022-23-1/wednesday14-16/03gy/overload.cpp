#include <iostream>

namespace sajt {
void increment(int *) {
  std::cout << "int*\n";
}
void increment(int) {
  std::cout << "int\n";
}
} // end of namespace sajt

//struct Complex {
//  int rel;
//  int im;
//};
//
//Complex operator+(Complex l, Complex r) {
//  Complex ret;
//  ret.rel = l.rel + r.rel;
//  ret.im = l.im + r.im;
//  return ret;
//}

int main() {
  sajt::increment(5);
  int i = 0;
  int *ptr = &i;
  sajt::increment(ptr);

  sajt::increment(0);
  //sajt::increment(NULL);
  sajt::increment(nullptr);
  

  //Complex a{4, 5};
  //Complex b{7, 6};
  //Complex add = a + b;
  //Complex add2 = operator+(a, b);
}
