#include <iostream>

template <class T, int Size>
int getArraySize(T (&t)[Size]) {
  std::cout << Size << '\n';
  return sizeof(t) / sizeof(t[0]);
}

int main() {
  int t[] = {1,2,3,4,5};

  std::string s[] = {"A", "B", "c", "D"};

  std::cout << getArraySize(t) << '\n';
  std::cout << getArraySize(s) << '\n';
}
