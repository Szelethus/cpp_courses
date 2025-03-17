#include <iostream>

int main() {
  const int k = 5;

  int c = 7;
  int i = 3;

  // konstansRA mutató mutató
  const int* ptr = &c;
  const int** qtr = &ptr;

  std::cout << k << '\n';
  std::cout << &k << '\n';
  std::cout << ptr << '\n';
  std::cout << *ptr << '\n';
  std::cout << &ptr << '\n';

  //*ptr = 6;
  ptr = &k;

  // konstans mutató
  int * const ctr = &c;

  *ctr = 10; 
  //ctr = &i;
  
  // konstansra mutató konstans mutató
  const int * const cctr = &k;

  int *nptr = 0;
  int *nnptr = NULL;
  int *nnnptr = nullptr;
}
