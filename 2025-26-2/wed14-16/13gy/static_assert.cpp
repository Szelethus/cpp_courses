#include <type_traits>

template <class T>
struct OnlyConst {
  static_assert(std::is_const<T>::value, "Not const");
};

int main() {
  OnlyConst<int> o;
}
