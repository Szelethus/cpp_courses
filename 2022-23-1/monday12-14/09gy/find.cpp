#include <iostream>
#include <list>
#include <vector>

template <class Iter, class Value>
Iter find(Iter begin, Iter end, Value value) {
  for (; begin != end; begin++)
    if (*begin == value)
      return begin;
  return end;
}

int main() {
  std::vector<int> vi{5, 4, 3, 6, 8};
  if (find(vi.begin(), vi.end(), 3) != vi.end())
    std::cout << "Benne van!\n";
  else
    std::cout << "Nincs benne!\n";

  std::vector<std::string> vs{"a", "b", "d", "c"};
  if (find(vs.begin(), vs.end(), std::string("a")) != vs.end())
    std::cout << "Benne van!\n";
  else
    std::cout << "Nincs benne!\n";

  std::list<std::string> ls{"a", "b", "d", "c"};
  if (find(ls.begin(), ls.end(), std::string("a")) != ls.end())
    std::cout << "Benne van!\n";
  else
    std::cout << "Nincs benne!\n";
}
