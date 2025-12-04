#include <iostream>
#include <vector>
#include <algorithm>

using vec_iter = std::vector<int>::iterator;

struct IsEven {
  bool operator()(int i) {
    return i % 2 == 0;
  }
};

int main() {
  std::vector<int> v = {1,2,3,4,5};
  vec_iter it = std::find_if(v.begin()+1, v.end()-1 , IsEven{});

  if (it == v.end())
    return -1;

  std::cout << *it << '\n';
}
