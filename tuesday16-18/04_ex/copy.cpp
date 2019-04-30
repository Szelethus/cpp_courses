#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

struct Store {
  int i;
  Store() = default;
  Store(int i_) : i(i_) {}

  Store(const Store &other) {
    std::cout << "Copy constructed!\n";
  }

  Store &operator=(const Store &other) {
    std::cout << "Copy assigned!\n";
    return *this;
  }
};

int main() {
  std::vector<Store> v = {
    Store(4), Store(6), Store(8), Store(9), Store(7), Store(0),
    Store(1), Store(2), Store(9), Store(5), Store(3), Store(1),
    Store(6), Store(4), Store(2), Store(6), Store(2), Store(0)
  };

  std::reverse(v.begin(), v.end());
};
