#include <iostream>
#include <vector>



int main() {
  std::vector<int> v{1,2,3};

  auto it = v.begin();
  it++;
  it++;
  // it += 2;
}
