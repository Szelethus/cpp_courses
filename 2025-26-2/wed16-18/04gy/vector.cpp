#include <iostream>
#include <vector>

int main() {
  std::vector<int> v;

  for (int i = 0; i < 10; ++i) {
    v.push_back(i);
  }

  //for (int i = 0; i < v.size(); ++i) {
  //  std::cout << v[i] << '\n';
  //}

  std::vector<int> v2(1000);

  for (int i = 0; i < 1005; ++i) {
    v2.at(i) = i;
  }
}
