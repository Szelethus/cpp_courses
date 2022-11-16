#include <iostream>
#include <set>

template <class Iter>
void printRange(Iter begin, Iter end) {
  for (; begin != end; ++begin)
    std::cout << *begin << '\n';
}

//using set_iter = std::set<int>::iterator;
//using set_const_iter = std::set<int>::const_iterator;
//
//void printSet(const std::set<int> &set) {
//  for (set_iter it = set.begin(); it != set.end(); ++it) {
//    std::cout << *it << '\n';
//  }
//}

struct Point {
  int x;
  int y;
};

struct LessByX {
  bool operator()(Point a, Point b) {
    return a.x < b.x;
  }
};

std::ostream &operator<<(std::ostream &out, Point p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

struct StringLength {
  bool operator()(const std::string &a, const std::string &b) {
    return a.size() <= b.size();
  }
};

using string_iter = std::set<std::string, StringLength>::iterator;

int main() {
  std::set<std::string, StringLength> strings;

  strings.insert("C++");
  strings.insert("Java");
  strings.insert("Haskell");
  strings.insert("GOD");

  string_iter it = strings.find("GOD");
  if (it != strings.end()) {
    std::cout << "Found: " << *it << '\n';
  }

  printRange(strings.begin(), strings.end());

  std::set<Point, LessByX> sp;

  sp.insert(Point{1, 5});
  sp.insert(Point{4, 3});
  sp.insert(Point{3, 2});
  sp.insert(Point{3, 6});

  //printRange(sp.begin(), sp.end());
  //std::set<int, std::less<int>> s = {3,2,5,7,1,8,4};
  //printSet(s);

  //s.insert(3);
  //set_iter it = s.find(4);

  //if (it != s.end()) {
  //  s.erase(it);
  //}
}
