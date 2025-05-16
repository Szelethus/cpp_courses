#include <iostream>
#include <vector>
#include <algorithm>

struct IsEven {
  bool operator()(int i) {
    return i % 2 == 0;
  }
};

int main() {
  std::vector<int> v{1,2,3,4,5};

  auto it = find(v.begin(), v.end(), 3);
  if (it == v.end())
    return -1;
  std::cout << *it << '\n';

  auto it2 = find_if(v.begin(), v.end(), IsEven{});
  if (it2 == v.end())
    return -1;
  std::cout << *it2 << '\n';
}
