#include <iostream>
#include <vector>

int main() {
  std::vector<int> v;

  v.resize(4);

  v[0] = 1;
  v[1] = 2;
  v[2] = 3;
  v[3] = 4;
  // v.push_back(1);
  // v.push_back(2);
  // v.push_back(3);
  // v.push_back(4);

  for (int i = 0; i < v.size(); ++i) {
    std::cout << v[i] << '\n';
  }
}
