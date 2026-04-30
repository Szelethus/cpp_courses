#include <iostream>
#include <vector>
#include <algorithm>

struct IsEven {
  bool operator()(int i) const {
    return i % 2 == 0;
  }
};

int main() {
  std::vector<int> v = {1,4,2,5,3,7,6};

  std::vector<int>::iterator it =
       std::remove_if(v.begin(), v.end(), IsEven{});

  v.erase(it, v.end());

  for (int i : v) {
    std::cout << i << '\n';
  }
}
