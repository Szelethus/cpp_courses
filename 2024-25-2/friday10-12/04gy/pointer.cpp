#include <cstddef>

int main() {
  const int k = 5;

  int c = 9;

  // konstansRA mutató mutató
  const int* ptr = &c;
  const int **qtr = &ptr;

  //*ptr = 6;
  
  ptr = &k;

  // konstans mutató
  int * const ktr = &c;

  *ktr = 5;

  // konstansRA mutató konstans mutató
  const int * const kptr = &k;

  int *nptr = 0;
  int *nnptr = NULL;
  int *nnnptr = nullptr;

  //std::cout << k << '\n';
  //std::cout << ptr << '\n';
  //std::cout << &k << '\n';
  //std::cout << *ptr << '\n';
  //std::cout << &ptr << '\n';
  //std::cout << &ptr << '\n';
  //std::cout << qtr << '\n';
  //std::cout << *qtr << '\n';
  //std::cout << **qtr << '\n';
}
