#include <iostream>

void f(int *t, int size) {
  std::cout << sizeof(int *) << ' ' << sizeof(t) << '\n';

  for (int i = 0; i < size; ++i)
    std::cout << *(t + i) << ' ' << t[i] << ' ' << i[t] << '\n';

}

int main() {
  int t[] = {1, 2, 3, 4, 5};

  std::cout << sizeof(int) << ' ' << sizeof(t) << '\n';
  
  std::cout << "arraylength: " << sizeof(t) / sizeof(t[0]) << '\n';

  f(t, sizeof(t) / sizeof(t[0]));
}
