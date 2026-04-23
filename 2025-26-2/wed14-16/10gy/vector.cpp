#include <iostream>
#include <vector>

int main() {
  std::vector<int> v;

  v.push_back(0);

  std::vector<int>::iterator it = v.begin();

  for (int i = 0; i < 1000; ++i)
    v.push_back(1);

  *it = 999;

  std::cout << v[0] << '\n';
}
