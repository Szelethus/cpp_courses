#include <iostream>
#include <vector>

template <class UnaryPred>
int find(const std::vector<int> &v, UnaryPred pred) {
  for (int i = 0; i < v.size(); ++i) {
    if (pred(v[i]))
      return i;
  }
  return -1;
}

struct IsSecondEven {
  bool isSecond = false;
  
  bool operator()(int i) {
    if (i % 2 == 0) {
      if (isSecond)
        return true;
      isSecond = true;
    }
    return false;
  }
};

int main() {
  std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};

  std::cout << find(v, IsSecondEven()) << '\n';
  std::cout << find(v, IsSecondEven()) << '\n';
}
