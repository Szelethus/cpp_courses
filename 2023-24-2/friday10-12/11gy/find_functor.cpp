#include <vector>

template <class Iter, class Pred> Iter find_if(Iter begin, Iter end, Pred pred) {

  for (; begin != end; ++begin) {
    if (pred(*begin))
      return begin;
  }
  return end;
}

// Funktor
struct IsSecond3 {
  bool isSecond = false;

  bool operator()(int i) {
    if (i == 3) {
      if (isSecond)
        return true;
      isSecond = true;
    }
    return false;
  }
};

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5, 3};
  std::vector<int>::iterator it = find_if(v.begin(), v.end(), IsSecond3{});

  if (it == v.end())
    return -1;
}
