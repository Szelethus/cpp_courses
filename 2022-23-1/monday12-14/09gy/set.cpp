#include <iostream>
#include <set>

// using set_iter = std::set<int>::iterator;
//
// void printSet(const std::set<int> &set) {
//   for (set_iter it = set.begin(); it != set.end(); ++it) {
//     std::cout << *it << '\n';
//   }
// }

struct Point {
  int x;
  int y;
};

struct LessByX {
  bool operator()(Point a, Point b) { return a.x < b.x; }
};

// using set_point_iter = std::set<Point, LessByX>::iterator;
//
// void printSet(const std::set<Point, LessByX> &set) {
//   for (set_point_iter it = set.begin(); it != set.end(); ++it) {
//     std::cout <<  "(" << it->x << ", " << it->y << ")" << '\n';
//   }
// }

template <class Iter> void printRange(Iter begin, Iter end) {
  for (; begin != end; ++begin)
    std::cout << *begin << '\n';
}

struct StringLength {
  bool operator()(std::string a, std::string b) {
    return a.size() <= b.size();
  }
};

int main() {
  std::set<Point, LessByX> sp;
  sp.insert(Point{1, 2});
  sp.insert(Point{3, 6});
  sp.insert(Point{5, 2});
  sp.insert(Point{5, 8});

  //printRange(sp.begin(), sp.end());

  std::set<std::string, StringLength> strings;
  strings.insert("C++");
  strings.insert("Haskell");
  strings.insert("Java");
  strings.insert("GOD");

  std::set<std::string, StringLength>::iterator it = strings.find("GOD");
  if (it != strings.end()) {
    std::cout << "GOD is: " << *it << '\n';
  }

  printRange(strings.begin(), strings.end());

  // std::set<int> s = {3,4,2,5,1,6,9,8,0,7};
  // s.insert(10);
  //
  // set_iter it = s.find(10);
  // if (it != s.end())
  //   s.erase(it);
  // printSet(s);
}
