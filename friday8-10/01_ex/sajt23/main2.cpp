#include <iostream>

int coin() {
  return -1;
}

int main() {
  for (unsigned i = coin(); i >= 0; ++i)
    std::cout << i << '\n';
}
