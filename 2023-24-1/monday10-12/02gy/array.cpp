#include <iostream>

void f(int *t, int size) {
  for (int i = 0; i < size; ++i) {
    std::cout << t[i] << '\n';
    std::cout << i[t] << '\n';
    std::cout << *(t + i) << '\n';
    std::cout << *(i + t) << '\n';
  }
} 

void g(int (&t)[5]) {
  std::cout << sizeof(t) << '\n';
}

int main() {
  int t[5] = {1,2,3,4,5};

  //std::cout << sizeof(int) << '\n';
  std::cout << sizeof(t) / sizeof(t[0]) << '\n';

  f(t, sizeof(t) / sizeof(t[0]));
  g(t);
}
