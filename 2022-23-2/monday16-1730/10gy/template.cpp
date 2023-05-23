#include <string>

template <class T>
void swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

int main() {
  int c = 5, d = 8;
  swap(c, d);

  std::string s1 = "alma";
  std::string s2 = "korte";
  swap(s1, s2);
}
