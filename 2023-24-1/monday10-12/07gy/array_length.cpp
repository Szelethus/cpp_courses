#include <iostream>

template <class T, int Size>
int getArraySize(T (&t)[Size]) {
  return sizeof(t) / sizeof(t[0]);
}

int main() {
  int t[] = {1,2,3,4};
  std::string s[] = {"a", "b", "c", "d", "e"};

  std::cout << getArraySize(t) << '\n';
  std::cout << getArraySize(s) << '\n';
}
