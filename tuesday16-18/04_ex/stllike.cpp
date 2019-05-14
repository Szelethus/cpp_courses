#include <iostream>
#include <vector>

struct SecondHigherThanFive {
  int count;
  SecondHigherThanFive() : count(0) {}

  bool operator()(int i) {
    if (i >= 5)
      ++count;
    return count == 2;
  }
};

struct FirstHigherThanTen {
  bool operator()(int i) { return i > 10; }
};

template <typename Iterator, class Compare>
Iterator myFind(Iterator begin, Iterator end, Compare op) {
  while (begin != end) {
    if (op(*begin)) {
      return begin;
    }
    ++begin;
  }
  return end;
}

int main() {
  std::vector<int> v1 = {0, 1, 2, 3, 3, 3, 3, 2, 7, 4, 5};
  std::vector<double> v2 = {0.5, 1.3, 2.78, 3.3, 3.2, 3.1,
                            3.9, 2.0, 7.2,  4.3, 5.2};

  // találjuk meg a második 7nél 5nél nagyobbegyenlő számot
  std::vector<int>::iterator it1 =
      myFind(v1.begin(), v1.end(), SecondHigherThanFive());

  if (it1 != v1.end())
    std::cout << "megvan";
  else
    std::cout << "nincs meg";

  std::cout << '\n';
  // találjuk meg egy 10nél nagyobb számot
  std::vector<double>::iterator it2 =
      myFind(v2.begin(), v2.end(), FirstHigherThanTen());

  if (it2 != v2.end())
    std::cout << "megvan";
  else
    std::cout << "nincs meg";
}
