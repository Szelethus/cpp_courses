#include <iostream>
#include <vector>

int main() {
  std::vector<int> v(500);

  for (int i = 0; i < v.size(); ++i) {
    //v.push_back(i);
    v[i] = i;
  }
}
