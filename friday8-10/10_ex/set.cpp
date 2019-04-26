#include <iostream>
#include <set>

struct Store {
  int i;
  Store(int i_) : i(i_) {}
};

bool operator<(const Store &lhs, const Store &rhs) {
  return lhs.i < rhs.i;
}

int main() {
  std::set<Store> s;

  for (int i = 10; i > 0; --i) {
    s.insert(Store(i));
  }

  for (auto it = s.rbegin(); it != s.rend(); ++it) {
    std::cout << it->i << '\n';
  }
}
