#include <cstdlib>
int main() {
  const char c = 'k';

  char *ptr = const_cast<char*>(&c);

  unsigned int i = 5;
  int i2 = static_cast<int>(i);

  int *ptr2 = reinterpret_cast<int *>(malloc(sizeof(int)));
}
