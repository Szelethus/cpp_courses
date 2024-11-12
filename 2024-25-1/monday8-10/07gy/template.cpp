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

  std::string str1 = "Hello";
  std::string str2 = "World";

  ::swap(str1, str2);

}
