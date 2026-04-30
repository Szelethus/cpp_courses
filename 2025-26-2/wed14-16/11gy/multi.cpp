#include <iostream>
#include <set>

int main() {
  std::multiset<int> s {1,2,2,2,2,2,3,4,5,5,5,5};

  for (const int &i : s)
    std::cout << i << '\n';
}
