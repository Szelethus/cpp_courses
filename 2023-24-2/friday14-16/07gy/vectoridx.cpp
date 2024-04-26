#include <iostream>
#include <vector>

int main() {
  std::vector<int> t = {1,2,3,4,5};

  for (int i = 0; i < t.size(); ++i) {
    std::cout << t[i] << '\n';
  }
}
