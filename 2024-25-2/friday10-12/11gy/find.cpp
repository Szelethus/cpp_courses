#include <iostream>
#include <list>
#include <vector>

using vec_iter = std::vector<int>::iterator;

template <class Iter, class UnaryPred>
Iter find(Iter begin, Iter end, UnaryPred pred) {
  for (; begin != end; ++begin) {
    if (pred(*begin))
      return begin;
  }
  return end;
}

struct IsEven {
  bool operator()(int i) {
    return i % 2 == 0;
  }
};

int main () {
  std::vector<int> v = {0,1,2,3,4,5,6,7,8,9};
  std::list<int> l = {0,1,2,3,4,5,6,7,8,9};

  auto it = find(l.begin(), l.end(), IsEven{});

  if (it == l.end())
    return -1;

  std::cout << "Found: " << *it << '\n';

}
