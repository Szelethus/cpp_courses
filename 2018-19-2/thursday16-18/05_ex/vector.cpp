#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

template <typename T>
struct Incr {
  int count;

  Incr() : count(0) {}

  void operator()(T &i) {
    ++count;
    if (count == 2)
      ++i;
  }
};

template <typename Iterator, typename Operand>
void forEach(Iterator begin, Iterator end, Operand op) {
  for (; begin != end; ++begin) {
    op(*begin);
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

  forEach(v.begin(), v.end(), Incr<int>());
  // TODO: kiszedni ezt value_typeal
  forEach(v2.begin(), v2.end(), Incr<double>());
  forEach(l.begin(), l.end(), Incr<int>());

  for (int i = 0; i < 5; ++i) {
    std::cout << v[i] << '\n'; // 0 2 2 3 4
    std::cout << v2[i] << '\n'; // 6.6 7.6 6.6 6.6 6.6
  }

  for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it) {
    std::cout << *it << '\n'; // 0 2 2 3 4
  }
  
}
