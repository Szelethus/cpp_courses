#include <cstddef>
#include <cstdint>

void foo(char &k) {}

int main() {
  const char c = 'k';

  foo(const_cast<char &>(c));

  int k = static_cast<int>(c);

  int *p = new int;

  std::intptr_t l = reinterpret_cast<std::intptr_t>(p);

  delete p;
}
