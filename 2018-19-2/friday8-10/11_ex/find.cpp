#include <iostream>
#include <vector>
#include <algorithm>

struct FindSecondHigherThanEight {
  int count;

  FindSecondHigherThanEight() : count(0) {}

  bool operator()(int i) {
    if (i > 8) {
      ++count;
      if (count == 2)
        return true;
    }
    return false;
  }
};

int main() {
  std::vector<int> v = { 1, 4, 10, 3, 9, 5, 3, 6 };

  std::vector<int>::iterator it =
      std::find_if(v.begin(), v.end(), FindSecondHigherThanEight());

  if (it != v.end())
    std::cout << *it << '\n';
}
