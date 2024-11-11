#include <iostream>
#include <vector>

typedef std::vector<int>::iterator vec_iter;

int main() {
  std::vector<int> v(500);

  for (int i = 0; i < 500; ++i) {
    //v.push_back(i);
    v[i] = i;
  }
}
