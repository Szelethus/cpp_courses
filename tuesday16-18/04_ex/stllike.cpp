#include <iostream>
#include <vector>

template <class T, class UnaryOp>
T find(T begin, T end, UnaryOp op) {
  while (begin != end) {
    if (op(*begin))
      return begin;
    ++begin;
  }
  return end;
}

struct FindSecondEvenNumber {
  int count;
  FindSecondEvenNumber() : count(0) {}

  bool operator()(int i) {
    if (i % 2 == 0)
      count++;

    return count == 2;
  }
};

int main() {
  std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8};

  std::vector<int>::iterator it = find(v.begin(), v.end(),
                                       FindSecondEvenNumber());

  if (it != v.end())
    std::cout << "Found second even number, which is " << *it << '\n';
  else
    std::cout << "There are no two even numbers within this range\n";
  
}
