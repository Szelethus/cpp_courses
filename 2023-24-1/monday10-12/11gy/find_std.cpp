#include <iostream>
#include <list>
#include <algorithm>

struct Even {
  bool operator()(int i) { return i%2 == 0; }
};

int main() {
  std::list<int> v = {1,2,3,4,5,6,7,8,9,10};

  std::list<int>::iterator it =
    std::find_if(v.begin(), v.end(), Even());

  if (it != v.end())
    std::cout << *it << '\n';
}
