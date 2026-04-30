#include <iostream>
#include <iterator>
#include <vector>
#include <list>

template <class Iter>
void my_advance_impl(Iter &it, int val,
                     std::bidirectional_iterator_tag tag) {

  std::cout << "SLOW\n";
  for (int i = 0; i < val; ++i)
    ++it;
}

template <class Iter>
void my_advance_impl(Iter &it, int val,
                    std::random_access_iterator_tag tag) {

  std::cout << "FAST\n";
  it = it + val;
}

template <class Iter>
void my_advance(Iter &it, int val) {
  typename Iter::iterator_category cat;

  my_advance_impl(it, val, cat);
}

int main() {
  std::vector<int> v = {1,2,3,4,5,6,7,8};

  std::vector<int>::iterator vecIt = v.begin();
  
  // hogyan léptetjük 3-mal előre?

  my_advance(vecIt, 3);

  std::list<int> l = {1,2,3,4,5,6,7,8};

  std::list<int>::iterator listIt = l.begin();

  // hogyan léptetjük 3-mal előre?

  my_advance(listIt, 3);
}
