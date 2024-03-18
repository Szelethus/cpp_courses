#include <iostream>
#include <vector>

int main() {
  std::vector<int> vi;

  vi.push_back(3);
  vi.push_back(4);
  vi.push_back(5);

  //std::cout << vi.size() << '\n';
  //std::cout << vi.capacity() << '\n';

  std::vector<std::string> vs;

  vs.resize(10);
  for (int i = 0; i < vs.size(); ++i) {
    vs[i] = std::to_string(i);
  }

  for (int i = 0; i < vs.size() + 10; ++i) {
    std::cout << vs.at(i) << '\n';
  }
}
