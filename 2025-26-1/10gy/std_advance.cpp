#include <list>
#include <vector>

int main() {
  std::vector<int> v = {1,2,3,4,5};
  std::list<int> l = {1,2,3,4,5};

  std::vector<int>::iterator vit = v.begin();
  std::list<int>::iterator lit = l.begin();

  advance(vit, 3);
  advance(lit, 3);
}
