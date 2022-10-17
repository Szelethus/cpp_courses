#include <vector>

template <class T>
struct X {
  const static int value = 0;
};

template <class T>
struct Y {
  const static int value = 1;
};

template <template <typename, typename> class Templ>
struct Z {
  Templ<int, std::allocator<int>> k;
};

int main() {
  Z<std::vector> z;
}
