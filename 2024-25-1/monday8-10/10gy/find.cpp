#include <iostream>
#include <algorithm>

struct IsEven {
  bool operator()(int i) const {
    return i % 2 == 0;
  }
};

int main() {
  std::vector<int> v{1,2,3,4,5,6};

  std::vector<int>::iterator it =
    find_if(v.begin(), v.end(), IsEven{});

  if (it == v.end()) {
    std::cout << "Not found\n";
  }

  std::cout << "Found: " << *it << '\n';
}
