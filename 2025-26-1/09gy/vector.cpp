#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec;

  for (int i = 0; i < 10; ++i) {
    vec.push_back(i);
    //std::cout << "vec size: " << vec.size() << '\n';
    //std::cout << "vec capacity: " << vec.capacity() << '\n';
  }

  std::vector<int> vec2 = {1,2,3,4,5,6,7,8,9,10};

  std::vector<int> vec10s(10);
  std::cout << vec10s.size() << '\n';
  std::cout << vec10s.capacity() << '\n';

  for (int i = 0; i < 10; ++i) {
    vec10s[i] = i;
    //vec10s.push_back(i);
    std::cout << "vec10s size: " << vec10s.size() << '\n';
    std::cout << "vec10s capacity: " << vec10s.capacity() << '\n';
  }

}
