#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "linked_list.h"

struct Point {
  int x;
  int y;
};

std::ostream &operator<<(std::ostream &out, Point p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

struct LessByX {
  bool operator()(Point a, Point b) {
    return a.x < b.x;
  }
};

bool operator==(Point a, Point b) {
  return a.x == b.x && a.y == b.y;
}

using vec_iter = std::vector<int>::iterator;
using set_iter = std::set<Point>::iterator;

int main() {
  std::vector<int> vec = {5, 2, 8, 6, 1};
  vec_iter vit = std::find(vec.begin(), vec.end(), 6);

  std::multiset<Point, LessByX> s;

  s.insert(Point{3, 2});
  s.insert(Point{3, 6});

  set_iter sit1 = s.find(Point{3, 6});
  if (sit1 != s.end())
    std::cout << *sit1 << '\n';
  
  set_iter sit2 = find(s.begin(), s.end(), Point{3, 6});
  if (sit2 != s.end())
    std::cout << *sit2 << '\n';
  else
    std::cout << "not found\n";
  std::cout << (Point{3,6} == Point{3,6}) << '\n';

  //List<int> l;
  //l.push_back(5);
  //l.push_back(2);
  //l.push_back(8);
  //l.push_back(6);
  //l.push_back(1);

  //List<int>::iterator lit = std::find(l.begin(), l.end(), 6);
}
