#include <iostream>

#define TANULO(NEPTUN, NAME, AGE) \
  std::cout << "Neptun: " << NEPTUN << ", név: " << NAME << ", kor: " << AGE << '\n';

int main() {
#include "paste.def"
}
