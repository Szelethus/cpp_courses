#include <iostream>

using string = std::string;

// FOR DEMONSTRATION PURPOSES, DON'T DO THIS!!!!!
#define PRINT(TYPE) \
void print ##TYPE(TYPE i) { \
  std::cout << i << '\n'; \
}

PRINT(int)
PRINT(string)

int main() {
  printstring("hello");
  printint(5);
}
