#include <iostream>
#include <vector>

int main() {
  std::vector<int> v = {1, 2, 3, 4};

  std::cout << "size: " << v.size() << '\n';
  std::cout << "2th : " << v[1] << '\n';
  std::cout << "capacity: " << v.capacity() << '\n';

  //v.resize(5);
  v.push_back(5);
  //v.shrink_to_fit();
  std::cout << "capacity: " << v.capacity() << '\n';
}
