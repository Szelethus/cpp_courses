#include <iostream>
#include <vector>

struct IsEven {
  int count = 0;
  bool operator()(int i) {
    if (i % 2 == 0)
      count++;
    return count == 2;
  }
};

using vec_iter = std::vector<int>::iterator;

template <class Iter, class UnaryPred>
Iter find(Iter begin, Iter end, UnaryPred op) {
  for (; begin != end; ++begin) {
    if (op(*begin))
      return begin;
  }
  return end;
}

int main() {
  std::vector<int> v{1,2,3,4,5,6};

  vec_iter it = find(v.begin(), v.end(), IsEven{});
  if (it != v.end())
    std::cout << "Found! " << *it << "\n";
}
