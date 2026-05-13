#include <iostream>

template <class T, class A = void>
struct has_Type {
  static const bool value = false;
};

template <class T>
struct has_Type<T, std::void_t<typename T::Type>> {
  static const bool value = true;
};

struct Alma {
  using Type = int;
};

struct Korte{};

int main() {
  std::cout << has_Type<Korte>::value << '\n'
            << has_Type<Alma>::value << '\n';
}
