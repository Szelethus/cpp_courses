#include <iostream>
#include <vector>

int main()  {
  std::vector<int> vec;

  for (int i = 0; i < 64; ++i) {
    vec.push_back(i);
    std::cout << "size(): " << vec.size() << '\n';
    std::cout << "capacity(): " << vec.capacity() << '\n';
  }

  std::vector<int>::iterator it = vec.begin();

  // minden interátort és pointert invalidálunk
  vec.push_back(5);

  std::cout << "before modifying: " << vec[0] << '\n';
  *it = 10;
  std::cout << "after  modifying: " << vec[0] << '\n';
}
