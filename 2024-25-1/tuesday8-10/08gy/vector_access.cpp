#include <iostream>
#include <vector>

typedef std::vector<int>::iterator vec_iter;

int main() {
  // C++11
  std::vector<int> v = {1,2,3,4,5,6,7,8,9};

  for (int i = 0; i < v.size(); ++i)
    std::cout << v[i] << '\n';

  for (int i = 0; i < v.size(); ++i)
    std::cout << v.at(i) << '\n';

  for (vec_iter it = v.begin(); it != v.end(); ++it) {
    int i = *it;
    std::cout << i << '\n';
  }

  // C++11
  for (int i : v)
    std::cout << i << '\n';

}
