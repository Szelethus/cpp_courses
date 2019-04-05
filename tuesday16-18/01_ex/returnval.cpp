#include <iostream>

int *f() {
  int i = 10;
  return &i;
}

int main() {

  int *p = f();

  std::cout << *p << '\n';
  
} 
