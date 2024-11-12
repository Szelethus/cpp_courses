#include <iostream>
#include <string>

void f1(int *t, int size) {}

void f2(int (&t)[5]) {}

template <class T, int Size>
int getSize(T (&t)[Size]) {
  return Size;
}

int main() {
  int t1[] = {1,2,3,4,5};
  int t2[] = {1,2,3,4};
  std::string st[] = {"a", "b"};

  f1(t1, sizeof(t1)/sizeof(t1[0]));
  f2(t1);

  std::cout << getSize(t1) << '\n';
  std::cout << getSize(st) << '\n';
}
