#include <iostream>
#include <vector>

template <class Iter, class T>
Iter find(
    Iter begin,
    Iter end,
    T value) {

  for (;begin != end; ++begin) {
    if (*begin == 3)
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
  std::vector<int> v = {1,2,3,4,5,3};
  find(v.begin(), v.end(), 3);
}
