#include <iostream>
#include <vector>

using vec_iter = std::vector<int>::iterator;

int sum(vec_iter begin, vec_iter end) {
  int sum = 0;
  for (; begin != end; ++begin) {
    sum += *begin;
  }
  return sum;
}


int main() {
  std::vector<int> vec = {15, 7, 5, 4};

  vec_iter start = vec.begin();
  vec_iter end = vec.end();

  std::cout << sum(start, end) << '\n';
  std::cout << sum(start + 1, end - 1) << '\n';
}
