#include <iostream>

int main() {
  int t[] = {1,2,3,4,5};

  for (int i = 0; i < sizeof(t)/sizeof(t[0]); ++i) {
    std::cout << t[i] << '\n';
  }
}
