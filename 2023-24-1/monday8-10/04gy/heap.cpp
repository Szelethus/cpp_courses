#include <iostream>

int main() {
  // malloc() -> operator new
  int *ptr = new int{5};
  // fee() -> operator delete
  
  std::cout << *ptr << '\n';

  delete ptr;
  ptr = nullptr;
  delete ptr;
}
