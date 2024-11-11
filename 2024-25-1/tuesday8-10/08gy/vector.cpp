#include <iostream>
#include <vector>

int main() {
  std::vector<int> v;

  for (int i = 0; i < 32; ++i) {
    v.push_back(i);
    //std::cout << "size: " << v.size() << '\n';
    //std::cout << "capacity: " << v.capacity() << '\n';
  }

  std::vector<int>::iterator it = v.begin();

  for (int i = 0; i < 1000; ++i)
    v.push_back(i);

  // iterátor invalidáció
  *it = 10;

  std::cout << v[0] << '\n';
}
