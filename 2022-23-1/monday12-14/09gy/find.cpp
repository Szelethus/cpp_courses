#include <iostream>
#include <list>
#include <vector>

std::vector<int>::iterator find(std::vector<int>::iterator begin,
                                std::vector<int>::iterator end, int value) {
  for (; begin != end; begin++)
    if (*begin == value)
      return begin;
  return end;
}

int main() {
  std::vector<int> vi{5,4,3,6,8};
  if (find(vi.begin(), vi.end(), 3) != vi.end())
    std::cout << "Benne van!\n";
  else
    std::cout << "Nincs benne!\n";


  //std::vector<std::string> vs{"a", "b", "d", "c"};
  //if (find(vs.begin(), vs.end(), "a") != vs.end())
  //  std::cout << "Benne van!\n";
  //else
  //  std::cout << "Nincs benne!\n";
}
