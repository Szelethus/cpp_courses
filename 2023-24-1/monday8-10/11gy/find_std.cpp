#include <iostream>
#include <algorithm>
#include <vector>

struct Even {
  bool operator()(int i) { return i % 2 == 0; }
};

int main()  {
  std::vector<int> v = {1,2,3,4,5};

  auto it = std::find_if(v.begin(), v.end(), Even());

  if (it != v.end())
    std::cout << *it << '\n';
}
