#include <iostream>
#include <vector>

using vec_iter = std::vector<int>::const_iterator;

//bool isSecondEven(int i) {
//  static int count = 0;
//  if (i % 2 == 0){
//    ++count;
//  }
//  if (count == 2) {
//    count = 0;
//    return true;
//  }
//  return false;
//}

struct IsSecondEven {
  int count = 0;

  bool operator()(int i) {
    if (i % 2 == 0)
      ++count;
    if (count == 2) {
      count = 0;
      return true;
    }
    return false;
  }
};

template <class UnaryPred>
vec_iter find(const std::vector<int> &vec, UnaryPred op) {
  for (vec_iter it = vec.begin(); it != vec.end(); ++it) {
    if (op(*it))
      return it;
  }
  return vec.end();
}

int main() {
  std::vector<int> vec = {1,2,3,4,5};

  vec_iter it = find(vec, IsSecondEven{});
  if (it == vec.end())
    return -1;
  std::cout << "found!: " << *it <<  '\n';
}
