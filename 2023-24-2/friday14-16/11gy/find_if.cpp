#include <iostream>
#include <vector>
#include <list>

template <class Iter, class Pred>
Iter find_if(Iter begin, Iter end, Pred pred) {
  for (Iter it = begin; it != end; ++it) {
    if (pred(*it))
      return it;
  }

  return end;
}

struct IsSecond3 {
  int threeCount = 0;

  bool operator()(int i) {
    if (i == 3) {
      threeCount++;
      if (threeCount == 2)
        return true;
    }
    return false;
  }
};

int main() {
  std::vector<int> v = {1,2,3,4,3,10};

  std::vector<int>::iterator it1 = find_if(v.begin(), v.end(),
                                        IsSecond3{});
  if (it1 == v.end()) {
    std::cout << "not found\n";
  }

  std::cout << *it1 << '\n';

  std::list<int> l = {1,2,3,4,3,10};

  auto it2 = find_if(l.begin(), l.end(), IsSecond3{});
  if (it2 == l.end()) {
    std::cout << "not found\n";
  }

  std::cout << *it2 << '\n';
}
