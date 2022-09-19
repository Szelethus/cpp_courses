#include <iostream>

int main() {
  int a = 6; 
  int b = 7;

  int *p = &a;
  int **qq = &p;

  int *q;

  int &ref = a;
  p = nullptr;

  const int * const *t;


  std::cout << &a << '\n';
  std::cout << *p << '\n';
}
