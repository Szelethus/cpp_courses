#include <iostream>
#include <vector>

int main() {
  // egyesével feltöltés
  std::vector<int> v;

  for (int i = 0; i < 10; ++i) {
    v.push_back(i);
    std::cout << v.size() << '\n';
    std::cout << v.capacity() << '\n';
  }

  // előre allokálás
  std::vector<int> v2(1000);

  for (int i = 0; i < 1000; ++i) {
    v.at(i) = i;
  }

  //for (int i = 0; i < v.size(); ++i) {
  //  std::cout << v[i] << '\n';
  //}
}
