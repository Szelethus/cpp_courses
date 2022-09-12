#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

template <typename Iterator>
void addOneToAllElements(Iterator begin, Iterator end) {
  for (; begin != end; ++begin) {
    (*begin)++;
  }
}

int main() {
  std::vector<int> v;
  std::vector<double> v2;

  std::list<int> l;

  for (int i = 0; i < 5; ++i) {
    v.push_back(i);
    v2.push_back(6.6);
    l.push_back(i);
  }

  addOneToAllElements(v.begin(), v.end());
  addOneToAllElements(v2.begin(), v2.end());
  addOneToAllElements(l.begin(), l.end());

  for (int i = 0; i < 5; ++i) {
    std::cout << v[i] << '\n';
    std::cout << v2[i] << '\n';
  }

  for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it) {
    std::cout << *it << '\n';
  }
  
}
