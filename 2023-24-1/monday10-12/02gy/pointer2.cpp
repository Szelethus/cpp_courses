#include <iostream>

int main() {
  const int k = 5;
  // konstransra mutató mutató
  const int *ptr = &k;
  //*ptr = 10;
  
  int c = 10;
  ptr = &c;

  std::cout << *ptr << '\n';
  c = 9;
  std::cout << *ptr << '\n';

  // konstans mutató
  int *const q = &c;

  *q = 55;
  
  int z = 0;
  //q = &z;
  
  // konstansra mutató konstans mutató
  const int *const r = &k;

  int *u = nullptr;
}
